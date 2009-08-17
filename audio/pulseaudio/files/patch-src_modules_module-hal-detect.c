--- src/modules/module-hal-detect.c.orig	2009-04-04 20:16:18.000000000 -0500
+++ src/modules/module-hal-detect.c	2009-08-16 16:09:49.000000000 -0500
@@ -293,7 +293,7 @@
 
     /* We only care for the main device */
     device = libhal_device_get_property_int(context, udi, "oss.device", &error);
-    if (dbus_error_is_set(&error) || device != 0)
+    if (dbus_error_is_set(&error))
         goto finish;
 
     r = TRUE;
