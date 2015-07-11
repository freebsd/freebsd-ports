--- mousepad/mousepad-settings.c.orig	2014-09-01 20:50:07 UTC
+++ mousepad/mousepad-settings.c
@@ -298,7 +298,7 @@ void
 mousepad_setting_set_string (const gchar *path,
                              const gchar *value)
 {
-  mousepad_setting_set (path, "s", value);
+  mousepad_setting_set (path, "s", value != NULL ? value : "");
 }
 
 
