--- dbus/dbus-sysdeps.c.orig	Mon Aug  9 23:03:37 2004
+++ dbus/dbus-sysdeps.c	Fri Dec 17 19:39:34 2004
@@ -738,12 +738,40 @@
 {
   int bytes_written;
   char buf[1] = { '\0' };
+#if defined(HAVE_CMSGCRED) && !defined(LOCAL_CREDS)
+  struct {
+	  struct cmsghdr hdr;
+	  struct cmsgcred cred;
+  } cmsg;
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
+  msg.msg_control = &cmsg;
+  msg.msg_controllen = sizeof (cmsg);
+  memset (&cmsg, 0, sizeof (cmsg));
+  cmsg.hdr.cmsg_len = sizeof (cmsg);
+  cmsg.hdr.cmsg_level = SOL_SOCKET;
+  cmsg.hdr.cmsg_type = SCM_CREDS;
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
@@ -797,8 +825,10 @@
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
@@ -833,9 +863,9 @@
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
@@ -858,9 +888,10 @@
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
@@ -886,13 +917,9 @@
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
@@ -3417,21 +3444,21 @@
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
   
