--- src/names.c.orig	Wed Dec  6 21:41:29 2000
+++ src/names.c	Fri Dec  2 16:12:26 2005
@@ -101,6 +101,21 @@
   return strcmp (first->name, second->name) == 0;
 }
 
+static void 
+alias_freer (void *param)
+{
+  RECODE_ALIAS alias = param;
+  struct recode_surface_list *next = alias->implied_surfaces;
+  struct recode_surface_list *p;
+  while (next)
+    {
+      p = next->next;
+      free(next);
+      next = p;
+    }  
+  free(alias);
+}
+
 bool
 prepare_for_aliases (RECODE_OUTER outer)
 {
@@ -108,7 +123,7 @@
   outer->number_of_symbols = 0;
 
   outer->alias_table
-    = hash_initialize (800, NULL, alias_hasher, alias_comparator, free);
+    = hash_initialize (800, NULL, alias_hasher, alias_comparator, alias_freer);
   if (!outer->alias_table)
     return false;
 
