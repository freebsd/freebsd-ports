--- plugins/dbus/dbus-plugin.c.orig	Sat Dec 31 14:13:15 2005
+++ plugins/dbus/dbus-plugin.c	Sat Dec 31 14:13:42 2005
@@ -152,7 +152,7 @@ init_dbus(void)
 
   if (!dbus_g_proxy_call (bus_proxy, "RequestName", &error,
                           G_TYPE_STRING, DBUS_SERVICE,
-                          G_TYPE_UINT, DBUS_NAME_FLAG_PROHIBIT_REPLACEMENT,
+                          G_TYPE_UINT, DBUS_NAME_FLAG_DO_NOT_QUEUE,
                           G_TYPE_INVALID,
                           G_TYPE_UINT, &request_name_result,
                           G_TYPE_INVALID))
