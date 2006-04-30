--- gedit/gedit-module.c.orig	Fri Jan  6 12:19:53 2006
+++ gedit/gedit-module.c	Fri Jan  6 12:20:21 2006
@@ -142,7 +142,7 @@ gedit_module_unload (GTypeModule *gmodul
 
 	gedit_debug_message (DEBUG_PLUGINS, "Unloading %s", module->path);
 
-	g_module_close (module->library);
+	/*g_module_close (module->library);*/
 
 	module->library = NULL;
 	module->type = 0;
