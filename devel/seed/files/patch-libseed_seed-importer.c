--- libseed/seed-importer.c.orig	2009-12-31 11:42:51.000000000 +0100
+++ libseed/seed-importer.c	2010-01-02 02:12:09.000000000 +0100
@@ -19,6 +19,8 @@
 
 #include <gio/gio.h>
 #include <string.h>
+#include <stdlib.h>
+#include <unistd.h>
 
 #include "seed-private.h"
 
@@ -636,8 +638,9 @@ seed_importer_handle_file (JSContextRef 
   JSValueRef js_file_dirname;
   JSObjectRef global, c_global;
   JSStringRef file_contents, file_name;
-  gchar *contents, *walk, *file_path, *canonical, *absolute_path;
+  gchar *contents, *walk, *file_path, *canonical, *absolute_path, *normalp;
   gchar *normalized_path;
+  gsize path_max;
 
   file_path = g_build_filename (dir, file, NULL);
   canonical = seed_importer_canonicalize_path (file_path);
@@ -691,15 +694,24 @@ seed_importer_handle_file (JSContextRef 
 					g_path_get_dirname (file_path), NULL);
     }
 
-  normalized_path = realpath (absolute_path, NULL);
+#ifdef PATH_MAX
+  path_max = PATH_MAX;
+#else
+  path_max = pathconf (absolute_path, _PC_PATH_MAX);
+  if (path_max <= 0)
+    path_max = 4096;
+#endif
+  normalized_path = (gchar *) g_malloc (path_max);
+  normalp = realpath (absolute_path, normalized_path);
 
-  js_file_dirname = seed_value_from_string (ctx, normalized_path, NULL);
+  js_file_dirname = seed_value_from_string (ctx, normalp, NULL);
 
   seed_object_set_property (nctx, global, "__script_path__", js_file_dirname);
 
   g_hash_table_insert (file_imports, canonical, global);
   g_free (file_path);
   g_free (absolute_path);
+  g_free (normalized_path);
 
   JSEvaluateScript (nctx, file_contents, NULL, file_name, 0, exception);
 
