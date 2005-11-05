--- shell/main.c.dbus-fix	2005-09-01 04:14:54.000000000 -0400
+++ shell/main.c	2005-09-01 04:15:33.000000000 -0400
@@ -152,7 +152,7 @@
 	if (!files) {
 #if DBUS_VERSION <= 33
 		call = dbus_g_proxy_begin_call (remote_object, "OpenWindow",
-						DBUS_TYPE_UINT32, timestamp,
+						DBUS_TYPE_UINT32, &timestamp,
 						DBUS_TYPE_INVALID);
 
 		if (!dbus_g_proxy_end_call (remote_object, call, &error, DBUS_TYPE_INVALID)) {
@@ -193,7 +193,7 @@
 		call = dbus_g_proxy_begin_call (remote_object, "OpenURI",
 						DBUS_TYPE_STRING, &uri,
 						DBUS_TYPE_STRING, &page_label,
-						DBUS_TYPE_UINT32, timestamp,
+						DBUS_TYPE_UINT32, &timestamp,
 						DBUS_TYPE_INVALID);
 
 		if (!dbus_g_proxy_end_call (remote_object, call, &error, DBUS_TYPE_INVALID)) {
