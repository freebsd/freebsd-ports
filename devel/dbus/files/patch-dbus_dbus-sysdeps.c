--- dbus/dbus-sysdeps.c.orig	Wed Mar 17 17:08:09 2004
+++ dbus/dbus-sysdeps.c	Thu Jul 22 01:25:51 2004
@@ -740,12 +740,38 @@
 {
   int bytes_written;
   char buf[1] = { '\0' };
+#if defined(HAVE_CMSGCRED) && !defined(LOCAL_CREDS)
+  char cmsgmem[CMSG_SPACE (sizeof (struct cmsgcred))];
+  struct cmsghdr *cmsg = (struct cmsghdr *) cmsgmem;
+  struct iovec iov;
+  struct msghdr msg;
+#endif
+
+#if defined(HAVE_CMSGCRED) && !defined(LOCAL_CREDS)
+  iov.iov_base = buf;
+  iov.iov_len = 1;
+
+  memset (&msg, 0, sizeof (msg));
+  msg.msg_iov = &iov;
+  msg.msg_iovlen = 1;
+
+  msg.msg_control = cmsg;
+  msg.msg_controllen = sizeof (cmsgmem);
+  memset (cmsg, 0, sizeof (cmsgmem));
+  cmsg->cmsg_len = sizeof (cmsgmem);
+  cmsg->cmsg_level = SOL_SOCKET;
+  cmsg->cmsg_type = SCM_CREDS;
+#endif
 
   _DBUS_ASSERT_ERROR_IS_CLEAR (error);
   
  again:
 
+#if defined(HAVE_CMSGCRED) && !defined(LOCAL_CREDS)
+  bytes_written = sendmsg (server_fd, &msg, 0);
+#else
   bytes_written = write (server_fd, buf, 1);
+#endif
 
   if (bytes_written < 0 && errno == EINTR)
     goto again;
@@ -862,7 +888,8 @@
 #ifdef HAVE_CMSGCRED
   if (cmsg->cmsg_len < sizeof (cmsgmem) || cmsg->cmsg_type != SCM_CREDS)
     {
-      dbus_set_error (error, DBUS_ERROR_FAILED);
+      dbus_set_error (error, DBUS_ERROR_FAILED,
+		      "Did not receive credentials");
       _dbus_verbose ("Message from recvmsg() was not SCM_CREDS\n");
       return FALSE;
     }
@@ -3421,21 +3448,21 @@
       exit (1);
     }
 
-  _dbus_string_init_const (&str, "0xff");
+  _dbus_string_init_const (&str, "255");
   if (!_dbus_string_parse_double (&str,
 				  0, &val, &pos))
     {
       _dbus_warn ("Failed to parse double");
       exit (1);
     }
-  if (val != 0xff)
+  if (val != 255)
     {
-      _dbus_warn ("Failed to parse 0xff correctly, got: %f", val);
+      _dbus_warn ("Failed to parse 255 correctly, got: %f", val);
       exit (1);
     }
-  if (pos != 4)
+  if (pos != 3)
     {
-      _dbus_warn ("_dbus_string_parse_double of \"0xff\" returned wrong position %d", pos);
+      _dbus_warn ("_dbus_string_parse_double of \"255\" returned wrong position %d", pos);
       exit (1);
     }
   
