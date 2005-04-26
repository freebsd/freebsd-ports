--- dbus-sysdeps.c.orig	Sat Mar  5 13:38:54 2005
+++ dbus-sysdeps.c	Tue Apr 26 01:59:05 2005
@@ -742,12 +742,40 @@ write_credentials_byte (int             
 {
   int bytes_written;
   char buf[1] = { '\0' };
+#if defined(HAVE_CMSGCRED) && (!defined(LOCAL_CREDS) || defined(__FreeBSD__))
+  struct {
+	  struct cmsghdr hdr;
+	  struct cmsgcred cred;
+  } cmsg;
+  struct iovec iov;
+  struct msghdr msg;
+#endif
+
+#if defined(HAVE_CMSGCRED) && (!defined(LOCAL_CREDS) || defined(__FreeBSD__))
+  iov.iov_base = buf;
+  iov.iov_len = 1;
+
+  memset (&msg, 0, sizeof (msg));
+  msg.msg_iov = &iov;
+  msg.msg_iovlen = 1;
+
+  msg.msg_control = &cmsg;
+  msg.msg_controllen = sizeof (cmsg);
+  memset (&cmsg, 0, sizeof (cmsg));
+  cmsg.hdr.cmsg_len = sizeof (cmsg);
+  cmsg.hdr.cmsg_level = SOL_SOCKET;
+  cmsg.hdr.cmsg_type = SCM_CREDS;
+#endif
 
   _DBUS_ASSERT_ERROR_IS_CLEAR (error);
   
  again:
 
+#if defined(HAVE_CMSGCRED) && (!defined(LOCAL_CREDS) || defined(__FreeBSD__))
+  bytes_written = sendmsg (server_fd, &msg, 0);
+#else
   bytes_written = write (server_fd, buf, 1);
+#endif
 
   if (bytes_written < 0 && errno == EINTR)
     goto again;
@@ -801,8 +829,10 @@ _dbus_read_credentials_unix_socket  (int
   char buf;
 
 #ifdef HAVE_CMSGCRED 
-  char cmsgmem[CMSG_SPACE (sizeof (struct cmsgcred))];
-  struct cmsghdr *cmsg = (struct cmsghdr *) cmsgmem;
+  struct {
+	  struct cmsghdr hdr;
+	  struct cmsgcred cred;
+  } cmsg;
 #endif
 
   _DBUS_ASSERT_ERROR_IS_CLEAR (error);
@@ -817,7 +847,7 @@ _dbus_read_credentials_unix_socket  (int
 
   _dbus_credentials_clear (credentials);
 
-#if defined(LOCAL_CREDS) && defined(HAVE_CMSGCRED)
+#if defined(LOCAL_CREDS) && defined(HAVE_CMSGCRED) && !defined(__FreeBSD__)
   /* Set the socket to receive credentials on the next message */
   {
     int on = 1;
@@ -837,9 +867,9 @@ _dbus_read_credentials_unix_socket  (int
   msg.msg_iovlen = 1;
 
 #ifdef HAVE_CMSGCRED
-  memset (cmsgmem, 0, sizeof (cmsgmem));
-  msg.msg_control = cmsgmem;
-  msg.msg_controllen = sizeof (cmsgmem);
+  memset (&cmsg, 0, sizeof (cmsg));
+  msg.msg_control = &cmsg;
+  msg.msg_controllen = sizeof (cmsg);
 #endif
 
  again:
@@ -862,9 +892,10 @@ _dbus_read_credentials_unix_socket  (int
     }
 
 #ifdef HAVE_CMSGCRED
-  if (cmsg->cmsg_len < sizeof (cmsgmem) || cmsg->cmsg_type != SCM_CREDS)
+  if (cmsg.hdr.cmsg_len < sizeof (cmsg) || cmsg.hdr.cmsg_type != SCM_CREDS)
     {
-      dbus_set_error (error, DBUS_ERROR_FAILED);
+      dbus_set_error (error, DBUS_ERROR_FAILED,
+		      "Did not receive credentials");
       _dbus_verbose ("Message from recvmsg() was not SCM_CREDS\n");
       return FALSE;
     }
@@ -890,13 +921,9 @@ _dbus_read_credentials_unix_socket  (int
 		       cr_len, (int) sizeof (cr), _dbus_strerror (errno));
       }
 #elif defined(HAVE_CMSGCRED)
-    struct cmsgcred *cred;
-
-    cred = (struct cmsgcred *) CMSG_DATA (cmsg);
-
-    credentials->pid = cred->cmcred_pid;
-    credentials->uid = cred->cmcred_euid;
-    credentials->gid = cred->cmcred_groups[0];
+    credentials->pid = cmsg.cred.cmcred_pid;
+    credentials->uid = cmsg.cred.cmcred_euid;
+    credentials->gid = cmsg.cred.cmcred_groups[0];
 #else /* !SO_PEERCRED && !HAVE_CMSGCRED */
     _dbus_verbose ("Socket credentials not supported on this OS\n");
 #endif
