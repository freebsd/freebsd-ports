--- tools/dbus-launch.c.orig	2008-04-05 11:34:21.000000000 -0500
+++ tools/dbus-launch.c	2008-04-05 11:36:12.000000000 -0500
@@ -966,7 +966,9 @@
       char write_pid_fd_as_string[MAX_FD_LEN];
       char write_address_fd_as_string[MAX_FD_LEN];
 
+#ifdef DBUS_BUILD_X11
       xdisplay = NULL;
+#endif
 
       if (close_stderr)
 	do_close_stderr ();
