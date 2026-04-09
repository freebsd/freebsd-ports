--- tools/browser/connection-binding-properties.c.orig	2020-11-08 20:23:20 UTC
+++ tools/browser/connection-binding-properties.c
@@ -147,7 +147,7 @@ connection_binding_properties_new_create (BrowserConne
 	part = g_new0 (BrowserVirtualConnectionPart, 1);
 	part->part_type = BROWSER_VIRTUAL_CONNECTION_PART_CNC;
 	part->u.cnc.table_schema = g_strdup (browser_connection_get_name (bcnc));
-	part->u.cnc.source_cnc = g_object_ref (G_OBJECT (bcnc));
+	part->u.cnc.source_cnc = (BrowserConnection *) g_object_ref (G_OBJECT (bcnc));
 	specs->parts = g_slist_append (NULL, part);
 
 	cprop = CONNECTION_BINDING_PROPERTIES (g_object_new (CONNECTION_TYPE_BINDING_PROPERTIES, NULL));
