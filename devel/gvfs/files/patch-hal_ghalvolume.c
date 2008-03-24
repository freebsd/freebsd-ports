--- hal/ghalvolume.c.orig	2008-02-25 16:51:39.000000000 -0500
+++ hal/ghalvolume.c	2008-02-25 16:52:00.000000000 -0500
@@ -550,7 +550,11 @@ g_hal_volume_new (GVolumeMonitor   *volu
         return NULL;
 
       /* TODO: other OS'es? Will address this with DK aka HAL 2.0 */
+#ifdef __FreeBSD__
+      device_path = hal_device_get_property_string (drive_device, "freebsd.device_file");
+#else
       device_path = hal_device_get_property_string (drive_device, "linux.device_file");
+#endif
       if (strlen (device_path) == 0)
         device_path = NULL;
 
