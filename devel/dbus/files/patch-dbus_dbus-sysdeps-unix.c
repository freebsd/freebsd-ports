--- dbus/dbus-sysdeps-unix.c.orig	2008-02-15 20:26:46.000000000 -0500
+++ dbus/dbus-sysdeps-unix.c	2008-02-15 20:28:46.000000000 -0500
@@ -1032,9 +1032,9 @@ write_credentials_byte (int             
   int bytes_written;
   char buf[1] = { '\0' };
 #if defined(HAVE_CMSGCRED) 
-  struct {
+  union {
 	  struct cmsghdr hdr;
-	  struct cmsgcred cred;
+	  char cred[CMSG_SPACE (sizeof (struct cmsgcred))];
   } cmsg;
   struct iovec iov;
   struct msghdr msg;
@@ -1045,10 +1045,10 @@ write_credentials_byte (int             
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
@@ -1124,9 +1124,9 @@ _dbus_read_credentials_socket  (int     
   pid_read = DBUS_PID_UNSET;
   
 #ifdef HAVE_CMSGCRED 
-  struct {
+  union {
     struct cmsghdr hdr;
-    struct cmsgcred cred;
+    char cred[CMSG_SPACE (sizeof (struct cmsgcred))];
   } cmsg;
 
 #elif defined(LOCAL_CREDS)
@@ -1163,8 +1163,8 @@ _dbus_read_credentials_socket  (int     
 
 #if defined(HAVE_CMSGCRED) || defined(LOCAL_CREDS)
   memset (&cmsg, 0, sizeof (cmsg));
-  msg.msg_control = &cmsg;
-  msg.msg_controllen = sizeof (cmsg);
+  msg.msg_control = (caddr_t) &cmsg;
+  msg.msg_controllen = CMSG_SPACE (sizeof (struct cmsgcred));
 #endif
 
  again:
@@ -1202,7 +1202,8 @@ _dbus_read_credentials_socket  (int     
     }
 
 #if defined(HAVE_CMSGCRED) || defined(LOCAL_CREDS)
-  if (cmsg.hdr.cmsg_len < sizeof (cmsg) || cmsg.hdr.cmsg_type != SCM_CREDS)
+  if (cmsg.hdr.cmsg_len < CMSG_LEN (sizeof (struct cmsgcred))
+		  || cmsg.hdr.cmsg_type != SCM_CREDS)
     {
       dbus_set_error (error, DBUS_ERROR_FAILED,
                       "Message from recvmsg() was not SCM_CREDS");
@@ -1229,8 +1230,11 @@ _dbus_read_credentials_socket  (int     
 		       cr_len, (int) sizeof (cr), _dbus_strerror (errno));
       }
 #elif defined(HAVE_CMSGCRED)
-    pid_read = cmsg.cred.cmcred_pid;
-    uid_read = cmsg.cred.cmcred_euid;
+    struct cmsgcred *cred;
+
+    cred = (struct cmsgcred *) CMSG_DATA (&cmsg);
+    pid_read = cred->cmcred_pid;
+    uid_read = cred->cmcred_euid;
 #elif defined(LOCAL_CREDS)
     pid_read = DBUS_PID_UNSET;
     uid_read = cmsg.cred.sc_uid;
