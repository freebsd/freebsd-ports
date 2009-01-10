--- monitor/gphoto2/ggphoto2volume.c.orig	2008-07-22 09:29:19.000000000 -0400
+++ monitor/gphoto2/ggphoto2volume.c	2008-07-22 23:22:30.000000000 -0400
@@ -277,7 +277,11 @@ g_gphoto2_volume_new (GVolumeMonitor   *
     return NULL;
 
   /* TODO: other OS'es? Will address this with DK aka HAL 2.0 */
+#ifdef __FreeBSD__
+  device_path = hal_device_get_property_string (drive_device, "freebsd.device_file");
+#else
   device_path = hal_device_get_property_string (drive_device, "linux.device_file");
+#endif
   if (strlen (device_path) == 0)
     device_path = NULL;
 
