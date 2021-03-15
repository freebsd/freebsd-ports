--- src/core/modules.c.orig	2021-03-13 16:34:06 UTC
+++ src/core/modules.c
@@ -214,7 +214,7 @@ MODULE_FILE_REC *module_register_full(const char *name
 		module = g_new0(MODULE_REC, 1);
 		module->name = g_strdup(name);
 
-                modules = g_slist_append(modules, module);
+                modules = g_slist_prepend(modules, module);
 	}
 
 	file = module_file_find(module, submodule);
@@ -226,7 +226,7 @@ MODULE_FILE_REC *module_register_full(const char *name
 	file->name = g_strdup(submodule);
         file->defined_module_name = g_strdup(defined_module_name);
 
-	module->files = g_slist_append(module->files, file);
+	module->files = g_slist_prepend(module->files, file);
         return file;
 }
 
