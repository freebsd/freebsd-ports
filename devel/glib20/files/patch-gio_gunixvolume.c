--- gio/gunixvolume.c.orig	2007-12-23 15:43:17.000000000 -0500
+++ gio/gunixvolume.c	2007-12-23 15:47:08.000000000 -0500
@@ -387,9 +387,13 @@ g_unix_volume_eject (GVolume    *volume,
                      gpointer             user_data)
 {
   GUnixVolume *unix_volume = G_UNIX_VOLUME (volume);
+#ifdef __FreeBSD__
+  char *argv[] = {"cdcontrol", "-f", NULL, "eject", NULL};
+  argv[2] = unix_volume->device_path;
+#else
   char *argv[] = {"eject", NULL, NULL};
-
   argv[1] = unix_volume->device_path;
+#endif
 
   eject_mount_do (volume, cancellable, callback, user_data, argv);
 }
