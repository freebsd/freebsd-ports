--- ./panel-plugin/xkb-config.c.orig	2011-03-21 11:32:35.000000000 +0100
+++ ./panel-plugin/xkb-config.c	2011-03-21 11:34:21.000000000 +0100
@@ -150,7 +150,7 @@
     config->application_map = g_hash_table_new (g_direct_hash, NULL);
 
     registry = xkl_config_registry_get_instance (config->engine);
-    xkl_config_registry_load (registry);
+    xkl_config_registry_load (registry, FALSE);
     
     config_item = xkl_config_item_new ();
 
@@ -214,7 +214,8 @@
 
     gdk_window_remove_filter (NULL, (GdkFilterFunc) handle_xevent, NULL);
 
-    xkl_engine_stop_listen (config->engine);
+    xkl_engine_stop_listen (config->engine,
+	XKLL_MANAGE_LAYOUTS | XKLL_MANAGE_WINDOW_STATES);
 }
 
 gint
@@ -547,7 +548,7 @@
     if (!config) return NULL;
 
     registry = xkl_config_registry_get_instance (config->engine);
-    xkl_config_registry_load (registry);
+    xkl_config_registry_load (registry, FALSE);
 
     return registry;
 }
