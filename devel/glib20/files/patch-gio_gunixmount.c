--- gio/gunixmount.c.orig	2007-12-23 15:53:50.000000000 -0500
+++ gio/gunixmount.c	2007-12-23 15:52:52.000000000 -0500
@@ -372,12 +372,18 @@ g_unix_mount_eject (GMount             *
                     gpointer             user_data)
 {
   GUnixMount *unix_mount = G_UNIX_MOUNT (mount);
+#ifndef __FreeBSD__
   char *argv[] = {"eject", NULL, NULL};
 
   if (unix_mount->mount_path != NULL)
     argv[1] = unix_mount->mount_path;
   else
     argv[1] = unix_mount->device_path;
+#else
+  char *argv[] = {"cdcontrol", "-f", NULL, "eject", NULL};
+
+  argv[2] = unix_mount->device_path;
+#endif
 
   return eject_unmount_do (mount, cancellable, callback, user_data, argv);
 }
