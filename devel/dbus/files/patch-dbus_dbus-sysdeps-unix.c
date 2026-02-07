--- dbus/dbus-sysdeps-unix.c.orig	2024-12-16 12:21:54 UTC
+++ dbus/dbus-sysdeps-unix.c
@@ -62,6 +62,10 @@
 #include <grp.h>
 #include <arpa/inet.h>
 
+#ifdef __FreeBSD__
+#include <sys/ucred.h>
+#endif
+
 #ifdef HAVE_ERRNO_H
 #include <errno.h>
 #endif
@@ -2372,6 +2376,25 @@ _dbus_read_credentials_socket  (DBusSocket       clien
       {
         pid_read = cr.unp_pid;
         uid_read = cr.unp_euid;
+      }
+#elif defined(LOCAL_PEERCRED)
+    struct xucred cr;
+    socklen_t cr_len = sizeof (cr);
+
+    if (getsockopt (client_fd.fd, 0, LOCAL_PEERCRED, &cr, &cr_len) != 0)
+      {
+        _dbus_verbose ("Failed to getsockopt(LOCAL_PEERCRED): %s\n",
+                       _dbus_strerror (errno));
+      }
+    else if (cr_len != sizeof (cr))
+      {
+        _dbus_verbose ("Failed to getsockopt(LOCAL_PEERCRED), returned %d bytes, expected %d\n",
+                       cr_len, (int) sizeof (cr));
+      }
+    else
+      {
+        pid_read = cr.cr_pid;
+        uid_read = cr.cr_uid;
       }
 #elif defined(HAVE_CMSGCRED)
     /* We only check for HAVE_CMSGCRED, but we're really assuming that the
