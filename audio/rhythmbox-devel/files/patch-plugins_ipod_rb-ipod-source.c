--- plugins/ipod/rb-ipod-source.c.orig	Sun Nov 19 12:12:33 2006
+++ plugins/ipod/rb-ipod-source.c	Sun Nov 19 12:28:50 2006
@@ -695,33 +695,36 @@ hal_udi_is_ipod (const char *udi)
 		char *spider_udi;
 		int vnd_id = 0;
 		int product_id = 0;
+		DBusError phone_error;
+
+		dbus_error_init (&phone_error);
 
 		spider_udi = g_strdup(parent_udi);
 		while (vnd_id == 0 && product_id == 0 && spider_udi != NULL) {
 			char *old_udi = spider_udi;
 			spider_udi =  libhal_device_get_property_string (ctx, spider_udi,
-					"info.parent", &error);
-			if (dbus_error_is_set (&error)) {
-				dbus_error_free (&error);
-				dbus_error_init (&error);
+					"info.parent", &phone_error);
+			if (dbus_error_is_set (&phone_error)) {
+				dbus_error_free (&phone_error);
+				dbus_error_init (&phone_error);
 				spider_udi = NULL;
 				break;
 			}
 			g_free(old_udi);
 
 			vnd_id = libhal_device_get_property_int (ctx, spider_udi,
-				"usb.vendor_id", &error);
-			if (dbus_error_is_set(&error)) {
-				dbus_error_free (&error);
-				dbus_error_init (&error);
+				"usb.vendor_id", &phone_error);
+			if (dbus_error_is_set(&phone_error)) {
+				dbus_error_free (&phone_error);
+				dbus_error_init (&phone_error);
 				vnd_id = 0;
 			}
 
 			product_id = libhal_device_get_property_int (ctx, spider_udi,
-				"usb.product_id", &error);
-			if (dbus_error_is_set(&error)) {
-				dbus_error_free (&error);
-				dbus_error_init (&error);
+				"usb.product_id", &phone_error);
+			if (dbus_error_is_set(&phone_error)) {
+				dbus_error_free (&phone_error);
+				dbus_error_init (&phone_error);
 				product_id = 0;
 			}
 		}
