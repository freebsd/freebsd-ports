--- src/engine.c.orig	2011-10-16 11:20:21.000000000 -0400
+++ src/engine.c	2012-01-09 13:20:15.000000000 -0500
@@ -194,8 +194,7 @@
 void
 ibus_hangul_init (IBusBus *bus)
 {
-    gboolean res;
-    GValue value = { 0, };
+    GVariant *var = NULL;
 
     hanja_table = hanja_table_load (NULL);
 
@@ -206,22 +205,20 @@
         g_object_ref_sink (config);
 
     hangul_keyboard = g_string_new_len ("2", 8);
-    res = ibus_config_get_value (config, "engine/Hangul",
-                                         "HangulKeyboard", &value);
-    if (res) {
-        const gchar* str = g_value_get_string (&value);
+    var = ibus_config_get_value (config, "engine/Hangul", "HangulKeyboard");
+    if (var) {
+        const gchar* str = g_variant_get_string (var, NULL);
         g_string_assign (hangul_keyboard, str);
-        g_value_unset(&value);
+        g_variant_unref(var);
     }
 
     hanja_key_list_init(&hanja_keys);
 
-    res = ibus_config_get_value (config, "engine/Hangul",
-                                         "HanjaKeys", &value);
-    if (res) {
-        const gchar* str = g_value_get_string (&value);
+    var = ibus_config_get_value (config, "engine/Hangul", "HanjaKeys");
+    if (var) {
+        const gchar* str = g_variant_get_string (var, NULL);
         hanja_key_list_set_from_string(&hanja_keys, str);
-        g_value_unset(&value);
+        g_variant_unref(var);
     } else {
 	hanja_key_list_append(&hanja_keys, IBUS_Hangul_Hanja, 0);
 	hanja_key_list_append(&hanja_keys, IBUS_F9, 0);
