--- plugins/symbol-db/plugin.c.orig	2009-04-17 01:08:28.000000000 -0400
+++ plugins/symbol-db/plugin.c	2009-04-17 01:09:11.000000000 -0400
@@ -1510,7 +1510,7 @@ do_check_offline_files_changed (SymbolDB
 	GHashTable *prj_elements_hash;
 	GPtrArray *to_add_files = NULL;
 	gint i;
-	gint real_added ;
+	gint real_added = 0;
 	
 	pm = anjuta_shell_get_interface (ANJUTA_PLUGIN (sdb_plugin)->shell,
 									 IAnjutaProjectManager, NULL);	
