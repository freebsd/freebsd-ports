--- src/mdh.c.orig	Thu Nov 13 02:17:50 2003
+++ src/mdh.c	Thu Nov 13 02:18:20 2003
@@ -140,6 +140,8 @@
 
 static void mdh_toolbar_custom_free(struct custom_t *obj)
 {
+    g_return_if_fail(obj != NULL);
+
     g_free(obj->value);
     g_free(obj->command);
     g_free(obj->tooltip);
@@ -147,6 +149,8 @@
 
 static void mdh_toolbar_panel_free(struct panel_t *obj)
 {
+    g_return_if_fail(obj != NULL);
+
     g_free(obj->value);
     g_free(obj->command);
     g_free(obj->tooltip);
@@ -186,8 +190,6 @@
     g_free(mdh_lock);
     g_free(mdh_cache);
     g_free(mdh_hist);
-
-    exit(0);
 }
 
 static void mdh_toolbar_init(void)
