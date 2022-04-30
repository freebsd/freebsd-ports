--- dbus/dbus-sysdeps-unix.c.orig	2020-07-02 09:08:39 UTC
+++ dbus/dbus-sysdeps-unix.c
@@ -4469,6 +4469,10 @@ _dbus_socket_can_pass_unix_fd (DBusSocket fd)
 void
 _dbus_close_all (void)
 {
+#ifdef __FreeBSD__
+  closefrom(3);
+#else
+#error Expected to be FreeBSD with closefrom()
   int maxfds, i;
 
 #ifdef __linux__
@@ -4525,6 +4528,7 @@ _dbus_close_all (void)
   /* close all inherited fds */
   for (i = 3; i < maxfds; i++)
     close (i);
+#endif
 }
 
 /**
