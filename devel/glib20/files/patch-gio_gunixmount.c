--- gio/gunixmount.c.orig	2014-09-21 13:00:08.875162804 +0200
+++ gio/gunixmount.c	2014-09-21 13:00:14.327163623 +0200
@@ -353,12 +353,17 @@
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
+   char *argv[] = {"cdcontrol", "-f", NULL, "eject", NULL};
+   argv[2] = unix_mount->device_path;
+#endif
 
   eject_unmount_do (mount, cancellable, callback, user_data, argv);
 }
