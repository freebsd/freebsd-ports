--- server/gam_channel.c.orig	Fri Jan 28 10:54:42 2005
+++ server/gam_channel.c	Sat Mar 26 16:15:55 2005
@@ -24,11 +24,53 @@
  * to check the server credentials early on.
  */
 static gboolean
-gam_client_conn_send_cred(GIOChannel * source, int fd)
+gam_client_conn_send_cred(int fd)
 {
     char data[2] = { 0, 0 };
+    int written;
+#if defined(HAVE_CMSGCRED) && !defined(LOCAL_CREDS)
+    struct {
+	    struct cmsghdr hdr;
+	    struct cmsgcred cred;
+    } cmsg;
+    struct iovec iov;
+    struct msghdr msg;
+
+    iov.iov_base = &data[0];
+    iov.iov_len = 1;
+
+    memset (&msg, 0, sizeof (msg));
+    msg.msg_iov = &iov;
+    msg.msg_iovlen = 1;
+
+    msg.msg_control = &cmsg;
+    msg.msg_controllen = sizeof (cmsg);
+    memset (&cmsg, 0, sizeof (cmsg));
+    cmsg.hdr.cmsg_len = sizeof (cmsg);
+    cmsg.hdr.cmsg_level = SOL_SOCKET;
+    cmsg.hdr.cmsg_type = SCM_CREDS;
+#endif
 
-    return(gam_client_conn_write(source, fd, &data[0], 1));
+retry:
+#if defined(HAVE_CMSGCRED) && !defined(LOCAL_CREDS)
+    written = sendmsg(fd, &msg, 0);
+#else
+    written = write(fd, &data[0], 1);
+#endif
+    if (written < 0) {
+        if (errno == EINTR)
+            goto retry;
+	gam_error(DEBUG_INFO,
+		  "Failed to write credential bytes to socket %d\n", fd);
+	return (-1);
+    }
+    if (written != 1) {
+	gam_error(DEBUG_INFO, "Wrote %d credential bytes to socket %d\n",
+		  written, fd);
+	return (-1);
+    }
+    GAM_DEBUG(DEBUG_INFO, "Wrote credential bytes to socket %d\n", fd);
+    return (written);
 }
 
 /**
@@ -49,8 +91,10 @@ gam_client_conn_check_cred(GIOChannel * 
     gid_t c_gid;
 
 #ifdef HAVE_CMSGCRED
-    char cmsgmem[CMSG_SPACE(sizeof(struct cmsgcred))];
-    struct cmsghdr *cmsg = (struct cmsghdr *) cmsgmem;
+    struct {
+	    struct cmsghdr hdr;
+	    struct cmsgcred cred;
+    } cmsg;
 #endif
 
     s_uid = getuid();
@@ -75,9 +119,9 @@ gam_client_conn_check_cred(GIOChannel * 
     msg.msg_iovlen = 1;
 
 #ifdef HAVE_CMSGCRED
-    memset(cmsgmem, 0, sizeof(cmsgmem));
-    msg.msg_control = cmsgmem;
-    msg.msg_controllen = sizeof(cmsgmem);
+    memset(&cmsg, 0, sizeof(cmsg));
+    msg.msg_control = &cmsg;
+    msg.msg_controllen = sizeof(cmsg);
 #endif
 
   retry:
@@ -94,7 +138,7 @@ gam_client_conn_check_cred(GIOChannel * 
         goto failed;
     }
 #ifdef HAVE_CMSGCRED
-    if (cmsg->cmsg_len < sizeof(cmsgmem) || cmsg->cmsg_type != SCM_CREDS) {
+    if (cmsg.hdr.cmsg_len < sizeof(cmsg) || cmsg.hdr.cmsg_type != SCM_CREDS) {
         GAM_DEBUG(DEBUG_INFO,
                   "Message from recvmsg() was not SCM_CREDS\n");
         goto failed;
@@ -120,13 +164,9 @@ gam_client_conn_check_cred(GIOChannel * 
             goto failed;
         }
 #elif defined(HAVE_CMSGCRED)
-        struct cmsgcred *cred;
-
-        cred = (struct cmsgcred *) CMSG_DATA(cmsg);
-
-        c_pid = cred->cmcred_pid;
-        c_uid = cred->cmcred_euid;
-        c_gid = cred->cmcred_groups[0];
+	c_pid = cmsg.cred.cmcred_pid;
+	c_uid = cmsg.cred.cmcred_euid;
+	c_gid = cmsg.cred.cmcred_groups[0];
 #else /* !SO_PEERCRED && !HAVE_CMSGCRED */
         GAM_DEBUG(DEBUG_INFO,
                   "Socket credentials not supported on this OS\n");
@@ -149,7 +189,7 @@ gam_client_conn_check_cred(GIOChannel * 
         goto failed;
     }
 
-    if (!gam_client_conn_send_cred(source, fd)) {
+    if (!gam_client_conn_send_cred(fd)) {
         GAM_DEBUG(DEBUG_INFO, "Failed to send credential byte to client\n");
         goto failed;
     }
@@ -305,6 +345,7 @@ gam_get_socket_path(const char *session)
         gam_client_id = g_getenv("GAM_CLIENT_ID");
         if (gam_client_id == NULL) {
             GAM_DEBUG(DEBUG_INFO, "Error getting GAM_CLIENT_ID\n");
+	    gam_client_id = "";
         }
     } else {
         gam_client_id = session;
