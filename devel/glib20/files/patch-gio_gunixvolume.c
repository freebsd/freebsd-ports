--- gio/gunixvolume.c.orig	2009-11-30 04:35:27.000000000 +0100
+++ gio/gunixvolume.c	2009-12-08 19:32:03.000000000 +0100
@@ -465,9 +465,14 @@ g_unix_volume_eject (GVolume            
                      gpointer             user_data)
 {
   GUnixVolume *unix_volume = G_UNIX_VOLUME (volume);
+#ifdef __FreeBSD__
+  char *argv[] = {"cdcontrol", "-f", NULL, "eject", NULL};
+  argv[2] = unix_volume->device_path;
+#else
   char *argv[] = { "eject", NULL, NULL };
 
   argv[1] = unix_volume->device_path;
+#endif
 
   eject_mount_do (volume, cancellable, callback, user_data, argv);
 }
