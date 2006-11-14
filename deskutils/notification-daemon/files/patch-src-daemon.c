--- src/daemon.c.orig	Sun Nov  5 08:59:12 2006
+++ src/daemon.c	Sun Nov  5 08:59:37 2006
@@ -1089,7 +1089,7 @@
 	dbus_conn = dbus_g_connection_get_connection(connection);
 
 	dbus_g_object_type_install_info(NOTIFY_TYPE_DAEMON,
-									&dbus_glib__object_info);
+									&dbus_glib_notify_daemon_object_info);
 
 	bus_proxy = dbus_g_proxy_new_for_name(connection,
 										  "org.freedesktop.DBus",
