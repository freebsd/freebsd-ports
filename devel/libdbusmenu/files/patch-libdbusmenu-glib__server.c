--- ./libdbusmenu-glib/server.c.orig	2012-10-03 15:54:22.000000000 +0000
+++ ./libdbusmenu-glib/server.c	2014-07-03 11:29:01.000000000 +0000
@@ -215,9 +215,9 @@
 static GDBusNodeInfo *            dbusmenu_node_info = NULL;
 static GDBusInterfaceInfo *       dbusmenu_interface_info = NULL;
 static const GDBusInterfaceVTable dbusmenu_interface_table = {
-	method_call:    bus_method_call,
-	get_property:   bus_get_prop,
-	set_property:   NULL /* No properties that can be set */
+	.method_call = bus_method_call,
+	.get_property = bus_get_prop,
+	.set_property = NULL /* No properties that can be set */
 };
 static method_table_t             dbusmenu_method_table[METHOD_COUNT];
 
