--- lib/ipc_socket.c.orig	2015-08-18 19:55:43 UTC
+++ lib/ipc_socket.c
@@ -60,7 +60,8 @@ set_sock_addr(struct sockaddr_un *addres
 
 static int32_t
 qb_ipc_dgram_sock_setup(const char *base_name,
-			const char *service_name, int32_t * sock_pt)
+			const char *service_name, int32_t * sock_pt,
+			gid_t gid)
 {
 	int32_t request_fd;
 	struct sockaddr_un local_address;
@@ -84,6 +85,10 @@ qb_ipc_dgram_sock_setup(const char *base
 #endif
 	res = bind(request_fd, (struct sockaddr *)&local_address,
 		   sizeof(local_address));
+#if !(defined(QB_LINUX) || defined(QB_CYGWIN))
+	chmod(local_address.sun_path, 0660);
+	chown(local_address.sun_path, -1, gid);
+#endif
 	if (res < 0) {
 		goto error_connect;
 	}
@@ -107,7 +112,7 @@ set_sock_size(int sockfd, size_t max_msg
 
 	rc = getsockopt(sockfd, SOL_SOCKET, SO_SNDBUF, &optval, &optlen);
 
-	qb_util_log(LOG_TRACE, "%d: getsockopt(%d, needed:%d) actual:%d",
+	qb_util_log(LOG_TRACE, "%d: getsockopt(%d, SO_SNDBUF, needed:%d) actual:%d",
 		rc, sockfd, max_msg_size, optval);
 
 	/* The optvat <= max_msg_size check is weird...
@@ -121,6 +126,29 @@ set_sock_size(int sockfd, size_t max_msg
 		optlen = sizeof(optval);
 		rc = setsockopt(sockfd, SOL_SOCKET, SO_SNDBUF, &optval, optlen);
 	}
+
+	if (rc != 0) {
+		return -errno;
+	}
+
+	rc = getsockopt(sockfd, SOL_SOCKET, SO_RCVBUF, &optval, &optlen);
+
+	qb_util_log(LOG_TRACE, "%d: getsockopt(%d, SO_RCVBUF, needed:%d) actual:%d",
+		rc, sockfd, max_msg_size, optval);
+
+	/* Set the sockets receive buffer size to match the send buffer.  Without
+	 * this calls to sendto() will result in an ENOBUFS error if the message
+	 * is larger than net.local.dgram.recvspace sysctl. */
+	if (rc == 0 && optval <= max_msg_size) {
+		optval = max_msg_size;
+		optlen = sizeof(optval);
+		rc = setsockopt(sockfd, SOL_SOCKET, SO_RCVBUF, &optval, optlen);
+	}
+
+	if (rc != 0) {
+		return -errno;
+	}
+
 	return rc;
 }
 
@@ -218,12 +246,12 @@ static int32_t
 qb_ipc_dgram_sock_connect(const char *base_name,
 			  const char *local_name,
 			  const char *remote_name,
-			  int32_t max_msg_size, int32_t * sock_pt)
+			  int32_t max_msg_size, int32_t * sock_pt, gid_t gid)
 {
 	char sock_path[PATH_MAX];
 	struct sockaddr_un remote_address;
 	int32_t res = qb_ipc_dgram_sock_setup(base_name, local_name,
-					      sock_pt);
+					      sock_pt, gid);
 	if (res < 0) {
 		return res;
 	}
@@ -544,14 +572,14 @@ qb_ipcc_us_connect(struct qb_ipcc_connec
 	fd_hdr = -1;
 
 	res = qb_ipc_dgram_sock_connect(r->response, "response", "request",
-					r->max_msg_size, &c->request.u.us.sock);
+					r->max_msg_size, &c->request.u.us.sock, c->egid);
 	if (res != 0) {
 		goto cleanup_hdr;
 	}
 	c->response.u.us.sock = c->request.u.us.sock;
 
 	res = qb_ipc_dgram_sock_connect(r->response, "event", "event-tx",
-					r->max_msg_size, &c->event.u.us.sock);
+					r->max_msg_size, &c->event.u.us.sock, c->egid);
 	if (res != 0) {
 		goto cleanup_hdr;
 	}
@@ -773,10 +801,16 @@ qb_ipcs_us_connect(struct qb_ipcs_servic
 
 	/* request channel */
 	res = qb_ipc_dgram_sock_setup(r->response, "request",
-				      &c->request.u.us.sock);
+				      &c->request.u.us.sock, c->egid);
 	if (res < 0) {
 		goto cleanup_hdr;
 	}
+
+	res = set_sock_size(c->request.u.us.sock, c->request.max_msg_size);
+	if (res != 0) {
+		goto cleanup_hdr;
+	}
+
 	c->setup.u.us.sock_name = NULL;
 	c->request.u.us.sock_name = NULL;
 
@@ -787,10 +821,16 @@ qb_ipcs_us_connect(struct qb_ipcs_servic
 
 	/* event channel */
 	res = qb_ipc_dgram_sock_setup(r->response, "event-tx",
-				      &c->event.u.us.sock);
+				      &c->event.u.us.sock, c->egid);
 	if (res < 0) {
 		goto cleanup_hdr;
 	}
+
+	res = set_sock_size(c->event.u.us.sock, c->event.max_msg_size);
+	if (res != 0) {
+		goto cleanup_hdr;
+	}
+
 	snprintf(path, PATH_MAX, "%s-%s", r->response, "event");
 	c->event.u.us.sock_name = strdup(path);
 
