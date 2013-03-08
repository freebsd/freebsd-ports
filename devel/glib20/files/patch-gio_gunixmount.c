--- gio/gunixmount.c.orig	2011-08-31 19:47:35.000000000 +0200
+++ gio/gunixmount.c	2011-09-15 17:50:24.000000000 +0200
@@ -449,12 +449,18 @@ g_unix_mount_eject (GMount             *
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
 
   eject_unmount_do (mount, cancellable, callback, user_data, argv);
 }
