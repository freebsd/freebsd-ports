--- src/libegg/egg-toolbar-editor.c.orig	Sat Jul  3 16:37:44 2004
+++ src/libegg/egg-toolbar-editor.c	Sat Jul  3 16:38:00 2004
@@ -102,12 +102,12 @@
 static gint
 compare_actions (gconstpointer a, gconstpointer b)
 {
-  g_return_val_if_fail (GTK_IS_ACTION (a), 0);
-  g_return_val_if_fail (GTK_IS_ACTION (b), 0);
-
   GValue value_a = { 0, }, value_b = { 0, };
   const char *short_label_a, *short_label_b;
   int ret;
+
+  g_return_val_if_fail (GTK_IS_ACTION (a), 0);
+  g_return_val_if_fail (GTK_IS_ACTION (b), 0);
 
   g_value_init (&value_a, G_TYPE_STRING);
   g_object_get_property (G_OBJECT (a), "short_label", &value_a);
