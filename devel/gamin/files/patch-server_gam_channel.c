--- server/gam_channel.c.orig	Tue Aug  9 18:17:39 2005
+++ server/gam_channel.c	Fri Oct 21 07:55:31 2005
@@ -30,10 +30,10 @@
 {
     char data[2] = { 0, 0 };
     int written;
-#if defined(HAVE_CMSGCRED) && !defined(LOCAL_CREDS)
-    struct {
+#if defined(HAVE_CMSGCRED) && (!defined(LOCAL_CREDS) || defined(__FreeBSD__))
+    union {
 	    struct cmsghdr hdr;
-	    struct cmsgcred cred;
+	    char cred[CMSG_SPACE (sizeof (struct cmsgcred))];
     } cmsg;
     struct iovec iov;
     struct msghdr msg;
@@ -45,16 +45,16 @@
     msg.msg_iov = &iov;
     msg.msg_iovlen = 1;
 
-    msg.msg_control = &cmsg;
-    msg.msg_controllen = sizeof (cmsg);
+    msg.msg_control = (caddr_t) &cmsg;
+    msg.msg_controllen = CMSG_SPACE (sizeof (struct cmsgcred));
     memset (&cmsg, 0, sizeof (cmsg));
-    cmsg.hdr.cmsg_len = sizeof (cmsg);
+    cmsg.hdr.cmsg_len = CMSG_LEN (sizeof (struct cmsgcred));
     cmsg.hdr.cmsg_level = SOL_SOCKET;
     cmsg.hdr.cmsg_type = SCM_CREDS;
 #endif
 
 retry:
-#if defined(HAVE_CMSGCRED) && !defined(LOCAL_CREDS)
+#if defined(HAVE_CMSGCRED) && (!defined(LOCAL_CREDS) || defined(__FreeBSD__))
     written = sendmsg(fd, &msg, 0);
 #else
     written = write(fd, &data[0], 1);
@@ -95,15 +95,16 @@
     gid_t c_gid;
 
 #ifdef HAVE_CMSGCRED
-    struct {
+    struct cmsgcred *cred;
+    union {
 	    struct cmsghdr hdr;
-	    struct cmsgcred cred;
+	    char cred[CMSG_SPACE (sizeof (struct cmsgcred))];
     } cmsg;
 #endif
 
     s_uid = getuid();
 
-#if defined(LOCAL_CREDS) && defined(HAVE_CMSGCRED)
+#if defined(LOCAL_CREDS) && defined(HAVE_CMSGCRED) && !defined(__FreeBSD__)
     /* Set the socket to receive credentials on the next message */
     {
         int on = 1;
@@ -124,8 +125,8 @@
 
 #ifdef HAVE_CMSGCRED
     memset(&cmsg, 0, sizeof(cmsg));
-    msg.msg_control = &cmsg;
-    msg.msg_controllen = sizeof(cmsg);
+    msg.msg_control = (caddr_t) &cmsg;
+    msg.msg_controllen = CMSG_SPACE (sizeof (struct cmsgcred));
 #endif
 
   retry:
@@ -142,7 +143,8 @@
         goto failed;
     }
 #ifdef HAVE_CMSGCRED
-    if (cmsg.hdr.cmsg_len < sizeof(cmsg) || cmsg.hdr.cmsg_type != SCM_CREDS) {
+    if (cmsg.hdr.cmsg_len < CMSG_LEN (sizeof (struct cmsgcred))
+		    || cmsg.hdr.cmsg_type != SCM_CREDS) {
         GAM_DEBUG(DEBUG_INFO,
                   "Message from recvmsg() was not SCM_CREDS\n");
         goto failed;
@@ -168,9 +170,10 @@
             goto failed;
         }
 #elif defined(HAVE_CMSGCRED)
-	c_pid = cmsg.cred.cmcred_pid;
-	c_uid = cmsg.cred.cmcred_euid;
-	c_gid = cmsg.cred.cmcred_groups[0];
+	cred = (struct cmsgcred *) CMSG_DATA (&cmsg);
+	c_pid = cred->cmcred_pid;
+	c_uid = cred->cmcred_euid;
+	c_gid = cred->cmcred_groups[0];
 #else /* !SO_PEERCRED && !HAVE_CMSGCRED */
         GAM_DEBUG(DEBUG_INFO,
                   "Socket credentials not supported on this OS\n");
@@ -513,66 +516,6 @@
     g_free(dir);
     return(FALSE);
 }
-
-/**
- * gam_check_secure_path:
- * @path: path to the (possibly abstract) socket
- *
- * Tries to create or ensure that the socket used for communicating with
- * the clients are in a safe directory to avoid possible attacks.
- *
- * Returns the socket file descriptor or -1 in case of error.
- */
-static gboolean
-gam_check_secure_path(const char *path)
-{
-    struct stat st;
-    int ret;
-
-    if (!gam_check_secure_dir())
-        return(FALSE);
-    /*
-     * Check the existing socket if any
-     */
-    ret = stat(path, &st);
-    if (ret < 0)
-	return(TRUE);
-    
-    if (st.st_uid != getuid()) {
-	gam_error(DEBUG_INFO,
-		  "Socket %s has different owner\n",
-		  path);
-	goto cleanup;
-    }
-#ifdef S_ISSOCK
-    if (!S_ISSOCK (st.st_mode)) {
-	gam_error(DEBUG_INFO, "Socket path %s is not a socket\n",
-		  path);
-	goto cleanup;
-    }
-#endif
-    if (st.st_mode & (S_IRWXG|S_IRWXO)) {
-	gam_error(DEBUG_INFO,
-		  "Socket %s has wrong permissions\n",
-		  path);
-	goto cleanup;
-    }
-    /*
-     * Looks good though binding may fail due to an existing server
-     */
-    return(TRUE);
-
-cleanup:
-    /*
-     * the existing file at the socket location seems strange, try to remove it
-     */
-    ret = unlink(path);
-    if (ret < 0) {
-	gam_error(DEBUG_INFO, "Failed to remove %s\n", path);
-	return(FALSE);
-    }
-    return(TRUE);
-}
 #endif /* ! HAVE_ABSTRACT_SOCKETS */
 
 /************************************************************************
@@ -620,6 +563,7 @@
 {
     int fd;
     struct sockaddr_un addr;
+    struct stat st;
 
     fd = socket(PF_UNIX, SOCK_STREAM, 0);
     if (fd < 0) {
@@ -635,13 +579,18 @@
     addr.sun_path[0] = '\0';
     strncpy(&addr.sun_path[1], path, (sizeof(addr) - 4) - 2);
 #else
-    /*
-     * if the socket is exposed at the filesystem level we need to take
-     * some extra protection checks. Also make sure the socket is created
-     * with restricted mode
-     */
-    if (!gam_check_secure_path(path)) {
+    if (! gam_check_secure_dir()) {
+      close(fd);
+      return (-1);
+    }
+
+    if (stat(path, &st) == 0) {
+      /* bind() will fail if the socket already exists */
+      if (unlink(path) < 0) {
+	GAM_DEBUG(DEBUG_INFO, "Failed to remove %s\n", path);
+	close(fd);
 	return (-1);
+      }
     }
     strncpy(&addr.sun_path[0], path, (sizeof(addr) - 4) - 1);
     umask(0077);
