--- gio/gunixvolume.c.orig	2014-03-20 04:50:45.000000000 +0100
+++ gio/gunixvolume.c	2014-03-24 20:44:40.000000000 +0100
@@ -356,9 +356,14 @@
                      gpointer             user_data)
 {
   GUnixVolume *unix_volume = G_UNIX_VOLUME (volume);
+#ifdef __FreeBSD__
+  const gchar *argv[] = {"cdcontrol", "-f", NULL, "eject", NULL};
+  argv[2] = unix_volume->device_path;
+#else
   const gchar *argv[] = { "eject", NULL, NULL };
 
   argv[1] = unix_volume->device_path;
+#endif
 
   eject_mount_do (volume, cancellable, callback, user_data, argv);
 }
