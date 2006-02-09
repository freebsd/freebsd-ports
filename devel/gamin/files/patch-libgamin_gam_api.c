--- libgamin/gam_api.c.orig	Tue Feb  7 17:49:07 2006
+++ libgamin/gam_api.c	Tue Feb  7 17:49:13 2006
@@ -14,6 +14,7 @@
 #include <sys/socket.h>
 #include <sys/un.h>
 #include <sys/uio.h>
+#include <string.h>
 #include "fam.h"
 #include "gam_protocol.h"
 #include "gam_data.h"
@@ -421,10 +422,10 @@
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
@@ -436,16 +437,16 @@
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
@@ -647,15 +648,16 @@
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
@@ -676,8 +678,8 @@
 
 #ifdef HAVE_CMSGCRED
     memset(&cmsg, 0, sizeof(cmsg));
-    msg.msg_control = &cmsg;
-    msg.msg_controllen = sizeof(cmsg);
+    msg.msg_control = (caddr_t) &cmsg;
+    msg.msg_controllen = CMSG_SPACE (sizeof (struct cmsgcred));
 #endif
 
 retry:
@@ -694,7 +696,7 @@
         goto failed;
     }
 #ifdef HAVE_CMSGCRED
-    if (cmsg.hdr.cmsg_len < sizeof(cmsg) || cmsg.hdr.cmsg_type != SCM_CREDS) {
+    if (cmsg.hdr.cmsg_len < CMSG_LEN (sizeof (struct cmsgcred)) || cmsg.hdr.cmsg_type != SCM_CREDS) {
         GAM_DEBUG(DEBUG_INFO,
                   "Message from recvmsg() was not SCM_CREDS\n");
         goto failed;
@@ -720,9 +722,10 @@
             goto failed;
         }
 #elif defined(HAVE_CMSGCRED)
-        c_pid = cmsg.cred.cmcred_pid;
-        c_uid = cmsg.cred.cmcred_euid;
-        c_gid = cmsg.cred.cmcred_groups[0];
+        cred = (struct cmsgcred *) CMSG_DATA (&cmsg);
+        c_pid = cred->cmcred_pid;
+        c_uid = cred->cmcred_euid;
+        c_gid = cred->cmcred_groups[0];
 #else /* !SO_PEERCRED && !HAVE_CMSGCRED */
         GAM_DEBUG(DEBUG_INFO,
                   "Socket credentials not supported on this OS\n");
@@ -1283,14 +1286,17 @@
 
     // FIXME: drop and reacquire lock while blocked?
     gamin_data_lock(conn);
-    if (!gamin_data_event_ready(conn)) {
+    while ((ret = gamin_data_event_ready(conn)) == 0) {
         if (gamin_read_data(conn, fc->fd, 1) < 0) {
 	    gamin_try_reconnect(conn, fc->fd);
 	    FAMErrno = FAM_CONNECT;
 	    return (-1);
 	}
     }
-    ret = gamin_data_read_event(conn, fe);
+
+    if (ret > 0)
+        ret = gamin_data_read_event(conn, fe);
+
     gamin_data_unlock(conn);
 
     if (ret < 0) {
