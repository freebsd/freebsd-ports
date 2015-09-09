--- src/engine.c.orig	2014-10-12 14:36:08 UTC
+++ src/engine.c
@@ -338,6 +338,7 @@ ibus_hangul_init (IBusBus *bus)
     value = ibus_config_get_value (config, "panel", "lookup-table-orientation");
     if (value != NULL) {
         lookup_table_orientation = g_variant_get_int32(value);
+        g_variant_unref (value);
     }
 
     keymap = ibus_keymap_get("us");
