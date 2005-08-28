--- dbus/dbus-sysdeps.c.orig	Wed Aug  3 13:42:56 2005
+++ dbus/dbus-sysdeps.c	Wed Aug 24 00:36:20 2005
@@ -742,16 +742,16 @@ write_credentials_byte (int             
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
 
@@ -759,10 +759,10 @@ write_credentials_byte (int             
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
@@ -771,7 +771,7 @@ write_credentials_byte (int             
   
  again:
 
-#if defined(HAVE_CMSGCRED) && !defined(LOCAL_CREDS)
+#if defined(HAVE_CMSGCRED)
   bytes_written = sendmsg (server_fd, &msg, 0);
 #else
   bytes_written = write (server_fd, buf, 1);
@@ -829,9 +829,10 @@ _dbus_read_credentials_unix_socket  (int
   char buf;
 
 #ifdef HAVE_CMSGCRED 
-  struct {
+  struct cmsgcred *cred;
+  union {
 	  struct cmsghdr hdr;
-	  struct cmsgcred cred;
+	  char cred[CMSG_SPACE (sizeof (struct cmsgcred))];
   } cmsg;
 #endif
 
@@ -847,7 +848,7 @@ _dbus_read_credentials_unix_socket  (int
 
   _dbus_credentials_clear (credentials);
 
-#if defined(LOCAL_CREDS) && defined(HAVE_CMSGCRED)
+#if defined(LOCAL_CREDS) && !defined(HAVE_CMSGCRED)
   /* Set the socket to receive credentials on the next message */
   {
     int on = 1;
@@ -868,8 +869,8 @@ _dbus_read_credentials_unix_socket  (int
 
 #ifdef HAVE_CMSGCRED
   memset (&cmsg, 0, sizeof (cmsg));
-  msg.msg_control = &cmsg;
-  msg.msg_controllen = sizeof (cmsg);
+  msg.msg_control = (caddr_t) &cmsg;
+  msg.msg_controllen = CMSG_SPACE (sizeof (struct cmsgcred));
 #endif
 
  again:
@@ -892,7 +893,8 @@ _dbus_read_credentials_unix_socket  (int
     }
 
 #ifdef HAVE_CMSGCRED
-  if (cmsg.hdr.cmsg_len < sizeof (cmsg) || cmsg.hdr.cmsg_type != SCM_CREDS)
+  if (cmsg.hdr.cmsg_len < CMSG_LEN (sizeof (struct cmsgcred))
+		  || cmsg.hdr.cmsg_type != SCM_CREDS)
     {
       dbus_set_error (error, DBUS_ERROR_FAILED,
                       "Message from recvmsg() was not SCM_CREDS");
@@ -920,9 +922,10 @@ _dbus_read_credentials_unix_socket  (int
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
 #else /* !SO_PEERCRED && !HAVE_CMSGCRED */
     _dbus_verbose ("Socket credentials not supported on this OS\n");
 #endif
