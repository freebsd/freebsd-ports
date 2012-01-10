--- src/engine.c.orig	2011-10-16 11:20:21.000000000 -0400
+++ src/engine.c	2012-01-09 19:40:48.000000000 -0500
@@ -130,7 +130,7 @@
 static void ibus_config_value_changed       (IBusConfig             *config,
                                              const gchar            *section,
                                              const gchar            *name,
-                                             GValue                 *value,
+                                             GVariant               *value,
                                              gpointer                user_data);
 
 static void        lookup_table_set_visible (IBusLookupTable        *table,
@@ -194,8 +194,7 @@
 void
 ibus_hangul_init (IBusBus *bus)
 {
-    gboolean res;
-    GValue value = { 0, };
+    GVariant* value;
 
     hanja_table = hanja_table_load (NULL);
 
@@ -206,22 +205,22 @@
         g_object_ref_sink (config);
 
     hangul_keyboard = g_string_new_len ("2", 8);
-    res = ibus_config_get_value (config, "engine/Hangul",
-                                         "HangulKeyboard", &value);
-    if (res) {
-        const gchar* str = g_value_get_string (&value);
+    value = ibus_config_get_value (config, "engine/Hangul",
+                                         "HangulKeyboard");
+    if (value != NULL) {
+        const gchar* str = g_variant_get_string (value, NULL);
         g_string_assign (hangul_keyboard, str);
-        g_value_unset(&value);
+        g_variant_unref(value);
     }
 
     hanja_key_list_init(&hanja_keys);
 
-    res = ibus_config_get_value (config, "engine/Hangul",
-                                         "HanjaKeys", &value);
-    if (res) {
-        const gchar* str = g_value_get_string (&value);
+    value = ibus_config_get_value (config, "engine/Hangul",
+                                         "HanjaKeys");
+    if (value != NULL) {
+        const gchar* str = g_variant_get_string (value, NULL);
         hanja_key_list_set_from_string(&hanja_keys, str);
-        g_value_unset(&value);
+        g_variant_unref(value);
     } else {
 	hanja_key_list_append(&hanja_keys, IBUS_Hangul_Hanja, 0);
 	hanja_key_list_append(&hanja_keys, IBUS_F9, 0);
@@ -990,23 +989,23 @@
 ibus_config_value_changed (IBusConfig   *config,
                            const gchar  *section,
                            const gchar  *name,
-                           GValue       *value,
+                           GVariant     *value,
                            gpointer      user_data)
 {
     IBusHangulEngine *hangul = (IBusHangulEngine *) user_data;
 
     if (strcmp(section, "engine/Hangul") == 0) {
         if (strcmp(name, "HangulKeyboard") == 0) {
-            const gchar *str = g_value_get_string (value);
+            const gchar *str = g_variant_get_string(value, NULL);
             g_string_assign (hangul_keyboard, str);
             hangul_ic_select_keyboard (hangul->context, hangul_keyboard->str);
         } else if (strcmp(name, "HanjaKeys") == 0) {
-            const gchar* str = g_value_get_string (value);
+            const gchar* str = g_variant_get_string(value, NULL);
 	    hanja_key_list_set_from_string(&hanja_keys, str);
         }
     } else if (strcmp(section, "panel") == 0) {
         if (strcmp(name, "lookup_table_orientation") == 0) {
-            lookup_table_orientation = g_value_get_int (value);
+            lookup_table_orientation = g_variant_get_int32(value);
         }
     }
 }
