--- dbus/dbus-sysdeps-unix.c.orig	Wed Nov  1 18:30:46 2006
+++ dbus/dbus-sysdeps-unix.c	Sun Nov  5 21:57:27 2006
@@ -834,10 +834,10 @@ write_credentials_byte (int             
 {
   int bytes_written;
   char buf[1] = { '\0' };
-#if defined(HAVE_CMSGCRED) 
-  struct {
+#if defined(HAVE_CMSGCRED)
+  union {
 	  struct cmsghdr hdr;
-	  struct cmsgcred cred;
+	  char cred[CMSG_SPACE (sizeof (struct cmsgcred))];
   } cmsg;
   struct iovec iov;
   struct msghdr msg;
@@ -848,10 +848,10 @@ write_credentials_byte (int             
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
@@ -918,9 +918,10 @@ _dbus_read_credentials_unix_socket  (int
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
@@ -957,8 +958,8 @@ _dbus_read_credentials_unix_socket  (int
 
 #if defined(HAVE_CMSGCRED) || defined(LOCAL_CREDS)
   memset (&cmsg, 0, sizeof (cmsg));
-  msg.msg_control = &cmsg;
-  msg.msg_controllen = sizeof (cmsg);
+  msg.msg_control = (caddr_t) &cmsg;
+  msg.msg_controllen = CMSG_SPACE (sizeof (struct cmsgcred));
 #endif
 
  again:
@@ -981,7 +982,8 @@ _dbus_read_credentials_unix_socket  (int
     }
 
 #if defined(HAVE_CMSGCRED) || defined(LOCAL_CREDS)
-  if (cmsg.hdr.cmsg_len < sizeof (cmsg) || cmsg.hdr.cmsg_type != SCM_CREDS)
+  if (cmsg.hdr.cmsg_len < CMSG_LEN (sizeof (struct cmsgcred))
+		  || cmsg.hdr.cmsg_type != SCM_CREDS)
     {
       dbus_set_error (error, DBUS_ERROR_FAILED,
                       "Message from recvmsg() was not SCM_CREDS");
@@ -1009,9 +1011,10 @@ _dbus_read_credentials_unix_socket  (int
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
@@ -2687,7 +2690,7 @@ _dbus_get_standard_session_servicedirs (
     }
   else
     {
-      if (!_dbus_string_append (&servicedir_path, "/usr/local/share:/usr/share:"))
+      if (!_dbus_string_append (&servicedir_path, "/usr/local/share:/usr/X11R6/share:/usr/share:"))
         goto oom;
     }
 
