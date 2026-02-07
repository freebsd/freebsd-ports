--- server/gam_channel.c.orig	Tue Aug  9 12:17:39 2005
+++ server/gam_channel.c	Fri Feb 10 01:22:46 2006
@@ -7,6 +7,7 @@
 #include <sys/stat.h>
 #include <sys/un.h>
 #include <sys/uio.h>
+#include <string.h>
 #include "gam_error.h"
 #include "gam_connection.h"
 #include "gam_channel.h"
@@ -30,10 +31,10 @@ gam_client_conn_send_cred(int fd)
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
@@ -45,16 +46,16 @@ gam_client_conn_send_cred(int fd)
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
@@ -95,15 +96,16 @@ gam_client_conn_check_cred(GIOChannel * 
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
@@ -124,8 +126,8 @@ gam_client_conn_check_cred(GIOChannel * 
 
 #ifdef HAVE_CMSGCRED
     memset(&cmsg, 0, sizeof(cmsg));
-    msg.msg_control = &cmsg;
-    msg.msg_controllen = sizeof(cmsg);
+    msg.msg_control = (caddr_t) &cmsg;
+    msg.msg_controllen = CMSG_SPACE (sizeof (struct cmsgcred));
 #endif
 
   retry:
@@ -142,7 +144,7 @@ gam_client_conn_check_cred(GIOChannel * 
         goto failed;
     }
 #ifdef HAVE_CMSGCRED
-    if (cmsg.hdr.cmsg_len < sizeof(cmsg) || cmsg.hdr.cmsg_type != SCM_CREDS) {
+    if (cmsg.hdr.cmsg_len < CMSG_LEN (sizeof (struct cmsgcred)) || cmsg.hdr.cmsg_type != SCM_CREDS) {
         GAM_DEBUG(DEBUG_INFO,
                   "Message from recvmsg() was not SCM_CREDS\n");
         goto failed;
@@ -168,9 +170,10 @@ gam_client_conn_check_cred(GIOChannel * 
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
@@ -620,6 +621,7 @@ gam_listen_unix_socket(const char *path)
 {
     int fd;
     struct sockaddr_un addr;
+    struct stat st;
 
     fd = socket(PF_UNIX, SOCK_STREAM, 0);
     if (fd < 0) {
@@ -640,8 +642,18 @@ gam_listen_unix_socket(const char *path)
      * some extra protection checks. Also make sure the socket is created
      * with restricted mode
      */
-    if (!gam_check_secure_path(path)) {
+    if (!gam_check_secure_dir()) {
+	close(fd);
 	return (-1);
+    }
+
+    if (stat(path, &st) == 0) {
+        /* bind() will fail if the socket already exists */
+        if (unlink(path) < 0) {
+            GAM_DEBUG(DEBUG_INFO, "Failed to remove %s\n", path);
+            close(fd);
+            return (-1);
+        }
     }
     strncpy(&addr.sun_path[0], path, (sizeof(addr) - 4) - 1);
     umask(0077);
