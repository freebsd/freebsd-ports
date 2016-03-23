--- lib/ipc_setup.c.orig	2015-08-18 19:55:43 UTC
+++ lib/ipc_setup.c
@@ -51,7 +51,10 @@ struct ipc_auth_ugp {
 struct ipc_auth_data {
 	int32_t sock;
 	struct qb_ipcs_service *s;
-	struct qb_ipc_connection_request msg;
+	union {
+		struct qb_ipc_connection_request req;
+		struct qb_ipc_connection_response res;
+	} msg;
 	struct msghdr msg_recv;
 	struct iovec iov_recv;
 	struct ipc_auth_ugp ugp;
@@ -311,12 +314,138 @@ qb_ipcc_us_sock_close(int32_t sock)
 	close(sock);
 }
 
+static int32_t
+qb_ipc_auth_creds(struct ipc_auth_data *data)
+{
+	int32_t res = 0;
+
+	/*
+	 * currently support getpeerucred, getpeereid, and SO_PASSCRED credential
+	 * retrieval mechanisms for various Platforms
+	 */
+#ifdef HAVE_GETPEERUCRED
+	/*
+	 * Solaris and some BSD systems
+	 */
+	{
+		ucred_t *uc = NULL;
+
+		if (getpeerucred(data->sock, &uc) == 0) {
+			res = 0;
+			data->ugp.uid = ucred_geteuid(uc);
+			data->ugp.gid = ucred_getegid(uc);
+			data->ugp.pid = ucred_getpid(uc);
+			ucred_free(uc);
+		} else {
+			res = -errno;
+		}
+	}
+#elif defined(HAVE_GETPEEREID)
+	/*
+	* Usually MacOSX systems
+	*/
+	{
+		/*
+		* TODO get the peer's pid.
+		* c->pid = ?;
+		*/
+		if (getpeereid(data->sock, &data->ugp.uid, &data->ugp.gid) == 0) {
+			res = 0;
+		} else {
+			res = -errno;
+		}
+	}
+
+#elif defined(SO_PASSCRED)
+	/*
+	* Usually Linux systems
+	*/
+	{
+		struct ucred cred;
+		struct cmsghdr *cmsg;
+
+		res = -EINVAL;
+		for (cmsg = CMSG_FIRSTHDR(&data->msg_recv); cmsg != NULL;
+			cmsg = CMSG_NXTHDR(&data->msg_recv, cmsg)) {
+			if (cmsg->cmsg_type != SCM_CREDENTIALS)
+				continue;
+
+			memcpy(&cred, CMSG_DATA(cmsg), sizeof(struct ucred));
+			res = 0;
+			data->ugp.pid = cred.pid;
+			data->ugp.uid = cred.uid;
+			data->ugp.gid = cred.gid;
+			break;
+		}
+	}
+#else /* no credentials */
+	data->ugp.pid = 0;
+	data->ugp.uid = 0;
+	data->ugp.gid = 0;
+	res = -ENOTSUP;
+#endif /* no credentials */
+
+	return res;
+}
+
+static void
+destroy_ipc_auth_data(struct ipc_auth_data *data)
+{
+	if (data->s) {
+		qb_ipcs_unref(data->s);
+	}
+
+#ifdef SO_PASSCRED
+	free(data->cmsg_cred);
+#endif
+	free(data);
+}
+
+static struct ipc_auth_data *
+init_ipc_auth_data(int sock, size_t len)
+{
+	struct ipc_auth_data *data = calloc(1, sizeof(struct ipc_auth_data));
+
+	if (data == NULL) {
+		return NULL;
+	}
+
+	data->msg_recv.msg_iov = &data->iov_recv;
+	data->msg_recv.msg_iovlen = 1;
+	data->msg_recv.msg_name = 0;
+	data->msg_recv.msg_namelen = 0;
+
+#ifdef SO_PASSCRED
+	data->cmsg_cred = calloc(1, CMSG_SPACE(sizeof(struct ucred)));
+	if (data->cmsg_cred == NULL) {
+		destroy_ipc_auth_data(data);
+		return NULL;
+	}
+	data->msg_recv.msg_control = (void *)data->cmsg_cred;
+	data->msg_recv.msg_controllen = CMSG_SPACE(sizeof(struct ucred));
+#endif
+#ifdef QB_SOLARIS
+	data->msg_recv.msg_accrights = 0;
+	data->msg_recv.msg_accrightslen = 0;
+#else
+	data->msg_recv.msg_flags = 0;
+#endif /* QB_SOLARIS */
+
+	data->len = len;
+	data->iov_recv.iov_base = &data->msg;
+	data->iov_recv.iov_len = data->len;
+	data->sock = sock;
+
+	return data;
+}
+
 int32_t
 qb_ipcc_us_setup_connect(struct qb_ipcc_connection *c,
 			 struct qb_ipc_connection_response *r)
 {
 	int32_t res;
 	struct qb_ipc_connection_request request;
+	struct ipc_auth_data *data;
 #ifdef QB_LINUX
 	int off = 0;
 	int on = 1;
@@ -340,22 +469,33 @@ qb_ipcc_us_setup_connect(struct qb_ipcc_
 		qb_ipcc_us_sock_close(c->setup.u.us.sock);
 		return res;
 	}
+
+	data = init_ipc_auth_data(c->setup.u.us.sock, sizeof(struct qb_ipc_connection_response));
+	if (data == NULL) {
+		qb_ipcc_us_sock_close(c->setup.u.us.sock);
+		return -ENOMEM;
+	}
+
+	qb_ipc_us_ready(&c->setup, NULL, -1, POLLIN);
+	res = qb_ipc_us_recv_msghdr(data);
+
 #ifdef QB_LINUX
 	setsockopt(c->setup.u.us.sock, SOL_SOCKET, SO_PASSCRED, &off,
 		   sizeof(off));
 #endif
 
-	res =
-	    qb_ipc_us_recv(&c->setup, r,
-			   sizeof(struct qb_ipc_connection_response), -1);
-	if (res < 0) {
+	if (res != data->len) {
+		destroy_ipc_auth_data(data);
 		return res;
 	}
 
-	if (r->hdr.error != 0) {
-		return r->hdr.error;
-	}
-	return 0;
+	memcpy(r, &data->msg.res, sizeof(struct qb_ipc_connection_response));
+
+	qb_ipc_auth_creds(data);
+	c->egid = data->ugp.gid;
+
+	destroy_ipc_auth_data(data);
+	return r->hdr.error;
 }
 
 /*
@@ -561,19 +701,6 @@ send_response:
 	return res;
 }
 
-static void
-destroy_ipc_auth_data(struct ipc_auth_data *data)
-{
-	if (data->s) {
-		qb_ipcs_unref(data->s);
-	}
-
-#ifdef SO_PASSCRED
-	free(data->cmsg_cred);
-#endif
-	free(data);
-}
-
 static int32_t
 process_auth(int32_t fd, int32_t revents, void *d)
 {
@@ -615,71 +742,7 @@ process_auth(int32_t fd, int32_t revents
 		goto cleanup_and_return;
 	}
 
-	/*
-	 * currently support getpeerucred, getpeereid, and SO_PASSCRED credential
-	 * retrieval mechanisms for various Platforms
-	 */
-#ifdef HAVE_GETPEERUCRED
-	/*
-	 * Solaris and some BSD systems
-	 */
-	{
-		ucred_t *uc = NULL;
-
-		if (getpeerucred(data->sock, &uc) == 0) {
-			res = 0;
-			data->ugp.uid = ucred_geteuid(uc);
-			data->ugp.gid = ucred_getegid(uc);
-			data->ugp.pid = ucred_getpid(uc);
-			ucred_free(uc);
-		} else {
-			res = -errno;
-		}
-	}
-#elif HAVE_GETPEEREID
-	/*
-	 * Usually MacOSX systems
-	 */
-	{
-		/*
-		 * TODO get the peer's pid.
-		 * c->pid = ?;
-		 */
-		if (getpeereid(data->sock, &data->ugp.uid, &data->ugp.gid) == 0) {
-			res = 0;
-		} else {
-			res = -errno;
-		}
-	}
-
-#elif SO_PASSCRED
-	/*
-	 * Usually Linux systems
-	 */
-	{
-		struct ucred cred;
-		struct cmsghdr *cmsg;
-
-		res = -EINVAL;
-		for (cmsg = CMSG_FIRSTHDR(&data->msg_recv); cmsg != NULL;
-		     cmsg = CMSG_NXTHDR(&data->msg_recv, cmsg)) {
-			if (cmsg->cmsg_type != SCM_CREDENTIALS)
-				continue;
-
-			memcpy(&cred, CMSG_DATA(cmsg), sizeof(struct ucred));
-			res = 0;
-			data->ugp.pid = cred.pid;
-			data->ugp.uid = cred.uid;
-			data->ugp.gid = cred.gid;
-			break;
-		}
-	}
-#else /* no credentials */
-	data->ugp.pid = 0;
-	data->ugp.uid = 0;
-	data->ugp.gid = 0;
-	res = -ENOTSUP;
-#endif /* no credentials */
+	res = qb_ipc_auth_creds(data);
 
 cleanup_and_return:
 #ifdef SO_PASSCRED
@@ -690,7 +753,7 @@ cleanup_and_return:
 
 	if (res < 0) {
 		close(data->sock);
-	} else if (data->msg.hdr.id == QB_IPC_MSG_AUTHENTICATE) {
+	} else if (data->msg.req.hdr.id == QB_IPC_MSG_AUTHENTICATE) {
 		(void)handle_new_connection(data->s, res, data->sock, &data->msg, data->len, &data->ugp);
 	} else {
 		close(data->sock);
@@ -709,7 +772,7 @@ qb_ipcs_uc_recv_and_auth(int32_t sock, s
 	int on = 1;
 #endif
 
-	data = calloc(1, sizeof(struct ipc_auth_data));
+	data = init_ipc_auth_data(sock, sizeof(struct qb_ipc_connection_request));
 	if (data == NULL) {
 		close(sock);
 		/* -ENOMEM */
@@ -719,34 +782,6 @@ qb_ipcs_uc_recv_and_auth(int32_t sock, s
 	data->s = s;
 	qb_ipcs_ref(data->s);
 
-	data->msg_recv.msg_iov = &data->iov_recv;
-	data->msg_recv.msg_iovlen = 1;
-	data->msg_recv.msg_name = 0;
-	data->msg_recv.msg_namelen = 0;
-
-#ifdef SO_PASSCRED
-	data->cmsg_cred = calloc(1,CMSG_SPACE(sizeof(struct ucred)));
-	if (data->cmsg_cred == NULL) {
-		close(sock);
-		destroy_ipc_auth_data(data);
-		/* -ENOMEM */
-		return;
-	}
-	data->msg_recv.msg_control = (void *)data->cmsg_cred;
-	data->msg_recv.msg_controllen = CMSG_SPACE(sizeof(struct ucred));
-#endif
-#ifdef QB_SOLARIS
-	data->msg_recv.msg_accrights = 0;
-	data->msg_recv.msg_accrightslen = 0;
-#else
-	data->msg_recv.msg_flags = 0;
-#endif /* QB_SOLARIS */
-
-	data->len = sizeof(struct qb_ipc_connection_request);
-	data->iov_recv.iov_base = &data->msg;
-	data->iov_recv.iov_len = data->len;
-	data->sock = sock;
-
 #ifdef SO_PASSCRED
 	setsockopt(sock, SOL_SOCKET, SO_PASSCRED, &on, sizeof(on));
 #endif
