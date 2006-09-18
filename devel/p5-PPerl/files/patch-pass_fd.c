--- pass_fd.c.orig	Thu Aug 22 16:37:09 2002
+++ pass_fd.c	Fri Sep 15 16:48:22 2006
@@ -93,73 +93,74 @@
 
 #else 
 
-struct cmessage {
-    struct cmsghdr cmsg;
-    int fd;
-};
+/* based on code from Postfix 2.3.3 (vk) */
+
+union {
+  struct cmsghdr just_for_alignment;
+  char    control[CMSG_SPACE(sizeof(int))];
+} control_un;
 
 int
-send_fd(int over, int this)
+send_fd(int over, int sendfd)
 {
-    struct iovec iov[1];
-    struct msghdr msg;
-    struct cmessage cm;
-    char sendbuf[] = "";
-
-    iov[0].iov_base = (char *)&sendbuf;
-    iov[0].iov_len = sizeof(sendbuf);
-    
-    cm.cmsg.cmsg_type  = SCM_RIGHTS;
-    cm.cmsg.cmsg_level = SOL_SOCKET;
-    cm.cmsg.cmsg_len = sizeof(struct cmessage);
-    cm.fd = this;
-
-    msg.msg_iov = iov;
-    msg.msg_iovlen = 1;
-    msg.msg_name = NULL;
-    msg.msg_namelen = 0;
-    msg.msg_control = (caddr_t)&cm;
-    msg.msg_controllen = sizeof(struct cmessage);
-    msg.msg_flags = 0;
-
-    if (sendmsg(over, &msg, 0) < 0)
-	return -1;
-    return 0;
+  struct iovec iov[1];
+  struct msghdr msg;
+  struct cmsghdr *cmptr;
+
+  memset((char *) &msg, 0, sizeof(msg));
+
+  msg.msg_control = control_un.control;
+  msg.msg_controllen = CMSG_LEN(sizeof(sendfd));
+
+  cmptr = CMSG_FIRSTHDR(&msg);
+  cmptr->cmsg_len = CMSG_LEN(sizeof(sendfd));
+  cmptr->cmsg_level = SOL_SOCKET;
+  cmptr->cmsg_type = SCM_RIGHTS;
+  *(int *) CMSG_DATA(cmptr) = sendfd;
+
+  msg.msg_name = NULL;
+  msg.msg_namelen = 0;
+
+  iov[0].iov_base = "";
+  iov[0].iov_len = 1;
+  msg.msg_iov = iov;
+  msg.msg_iovlen = 1;
+
+  if (sendmsg(over, &msg, 0) < 0)
+    return -1;
+  return 0;
 }
 
 int 
 recv_fd(int over)
 {
-    struct iovec iov[1];
     struct msghdr msg;
-    struct cmessage cm;
-    ssize_t got;
-    char recbuf;
-
-    /* in examples this was >1 but this causes too much to be read,
-     * causing sync issues */
+    struct iovec iov[1];
+    char    buf[1];
+    struct cmsghdr *cmptr;
 
-    iov[0].iov_base = &recbuf;
-    iov[0].iov_len = 1;
+    memset((char *) &msg, 0, sizeof(msg));
+    msg.msg_control = control_un.control;
+    msg.msg_controllen = CMSG_LEN(sizeof(int));
 
-    bzero((char *)&cm, sizeof(cm));
-    bzero((char *)&msg, sizeof(msg));
+    msg.msg_name = 0;
+    msg.msg_namelen = 0;
 
+    iov[0].iov_base = buf;
+    iov[0].iov_len = sizeof(buf);
     msg.msg_iov = iov;
     msg.msg_iovlen = 1;
-    msg.msg_name = NULL;
-    msg.msg_namelen = 0;
-    msg.msg_control = (caddr_t)&cm;
-    msg.msg_controllen = sizeof(struct cmessage);
-    msg.msg_flags = 0;
-
-    if ((got = recvmsg(over, &msg, 0)) < 0)
-	return -1;
 
-    if (cm.cmsg.cmsg_type != SCM_RIGHTS)
-	return -1;
+    if (recvmsg(over, &msg, 0) < 0)
+	return (-1);
 
-    return cm.fd;
+    if ((cmptr = CMSG_FIRSTHDR(&msg)) != 0
+	&& cmptr->cmsg_len == CMSG_LEN(sizeof(int))) {
+	if (cmptr->cmsg_level != SOL_SOCKET || cmptr->cmsg_type != SCM_RIGHTS)
+	  return(-1);			    /* error */
+	return (*(int *) CMSG_DATA(cmptr)); /* the file handle */
+    } else
+	return (-1);
 }
 
 #endif
