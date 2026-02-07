--- src/outer.c.orig	Wed Aug 30 23:16:14 2000
+++ src/outer.c	Fri Dec  2 16:12:26 2005
@@ -617,7 +617,14 @@
   if (outer->alias_table)
     hash_free (outer->alias_table);
   if (outer->argmatch_charset_array)
-    free (outer->argmatch_charset_array);
+    {
+      char **cursor;
+      for (cursor = outer->argmatch_charset_array; *cursor; cursor++)
+	free (*cursor);
+      for (cursor = outer->argmatch_surface_array; *cursor; cursor++)
+	free (*cursor);
+      free (outer->argmatch_charset_array);
+    }
   if (outer->one_to_same)
     free ((void *) outer->one_to_same);
   free (outer);
