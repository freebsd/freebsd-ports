--- dbus/dbus-sysdeps-unix.c.orig	Thu Sep 14 01:07:11 2006
+++ dbus/dbus-sysdeps-unix.c	Sat Oct  7 12:23:40 2006
@@ -719,16 +719,16 @@ write_credentials_byte (int             
 {
   int bytes_written;
   char buf[1] = { '\0' };
-#if defined(HAVE_CMSGCRED) && !defined(LOCAL_CREDS)
-  struct {
+#if defined(HAVE_CMSGCRED)
+  union {
 	  struct cmsghdr hdr;
-	  struct cmsgcred cred;
+	  char cred[CMSG_SPACE (sizeof (struct cmsgcred))];
   } cmsg;
   struct iovec iov;
   struct msghdr msg;
 #endif
 
-#if defined(HAVE_CMSGCRED) && !defined(LOCAL_CREDS)
+#if defined(HAVE_CMSGCRED)
   iov.iov_base = buf;
   iov.iov_len = 1;
 
@@ -736,10 +736,10 @@ write_credentials_byte (int             
   msg.msg_iov = &iov;
   msg.msg_iovlen = 1;
 
-  msg.msg_control = &cmsg;
-  msg.msg_controllen = sizeof (cmsg);
+  msg.msg_control = (caddr_t) &cmsg;
+  msg.msg_controllen = CMSG_SPACE (sizeof (struct cmsgcred));
   memset (&cmsg, 0, sizeof (cmsg));
-  cmsg.hdr.cmsg_len = sizeof (cmsg);
+  cmsg.hdr.cmsg_len = CMSG_LEN (sizeof (struct cmsgcred));
   cmsg.hdr.cmsg_level = SOL_SOCKET;
   cmsg.hdr.cmsg_type = SCM_CREDS;
 #endif
@@ -748,7 +748,7 @@ write_credentials_byte (int             
   
  again:
 
-#if defined(HAVE_CMSGCRED) && !defined(LOCAL_CREDS)
+#if defined(HAVE_CMSGCRED)
   bytes_written = sendmsg (server_fd, &msg, 0);
 #else
   bytes_written = write (server_fd, buf, 1);
@@ -806,9 +806,10 @@ _dbus_read_credentials_unix_socket  (int
   char buf;
 
 #ifdef HAVE_CMSGCRED 
-  struct {
+  struct cmsgcred *cred;
+  union {
 	  struct cmsghdr hdr;
-	  struct cmsgcred cred;
+	  char cred[CMSG_SPACE (sizeof (struct cmsgcred))];
   } cmsg;
 
 #elif defined(LOCAL_CREDS)
@@ -845,8 +846,8 @@ _dbus_read_credentials_unix_socket  (int
 
 #if defined(HAVE_CMSGCRED) || defined(LOCAL_CREDS)
   memset (&cmsg, 0, sizeof (cmsg));
-  msg.msg_control = &cmsg;
-  msg.msg_controllen = sizeof (cmsg);
+  msg.msg_control = (caddr_t) &cmsg;
+  msg.msg_controllen = CMSG_SPACE (sizeof (struct cmsgcred));
 #endif
 
  again:
@@ -869,7 +870,8 @@ _dbus_read_credentials_unix_socket  (int
     }
 
 #if defined(HAVE_CMSGCRED) || defined(LOCAL_CREDS)
-  if (cmsg.hdr.cmsg_len < sizeof (cmsg) || cmsg.hdr.cmsg_type != SCM_CREDS)
+  if (cmsg.hdr.cmsg_len < CMSG_LEN (sizeof (struct cmsgcred))
+		  || cmsg.hdr.cmsg_type != SCM_CREDS)
     {
       dbus_set_error (error, DBUS_ERROR_FAILED,
                       "Message from recvmsg() was not SCM_CREDS");
@@ -897,9 +899,10 @@ _dbus_read_credentials_unix_socket  (int
 		       cr_len, (int) sizeof (cr), _dbus_strerror (errno));
       }
 #elif defined(HAVE_CMSGCRED)
-    credentials->pid = cmsg.cred.cmcred_pid;
-    credentials->uid = cmsg.cred.cmcred_euid;
-    credentials->gid = cmsg.cred.cmcred_groups[0];
+    cred = (struct cmsgcred *) CMSG_DATA (&cmsg);
+    credentials->pid = cred->cmcred_pid;
+    credentials->uid = cred->cmcred_euid;
+    credentials->gid = cred->cmcred_groups[0];
 #elif defined(LOCAL_CREDS)
     credentials->pid = DBUS_PID_UNSET;
     credentials->uid = cmsg.cred.sc_uid;
