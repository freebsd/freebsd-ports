Index: gnome-initial-setup/pages/language/gis-language-page.c
--- gnome-initial-setup/pages/language/gis-language-page.c.orig	2022-12-02 15:11:34 UTC
+++ gnome-initial-setup/pages/language/gis-language-page.c
@@ -126,15 +126,17 @@ language_changed (CcLanguageChooser  *chooser,
   gis_driver_set_user_language (driver, priv->new_locale_id, TRUE);
   gtk_widget_set_default_direction (gtk_get_locale_direction ());
 
-  if (gis_driver_get_mode (driver) == GIS_DRIVER_MODE_NEW_USER) {
-      if (g_permission_get_allowed (priv->permission)) {
-          set_localed_locale (page);
-      }
-      else if (g_permission_get_can_acquire (priv->permission)) {
-          g_permission_acquire_async (priv->permission,
-                                      NULL,
-                                      change_locale_permission_acquired,
-                                      page);
+  if (priv->permission != NULL) {
+      if (gis_driver_get_mode (driver) == GIS_DRIVER_MODE_NEW_USER) {
+          if (g_permission_get_allowed (priv->permission)) {
+              set_localed_locale (page);
+          }
+          else if (g_permission_get_can_acquire (priv->permission)) {
+              g_permission_acquire_async (priv->permission,
+                                          NULL,
+                                          change_locale_permission_acquired,
+                                          page);
+          }
       }
   }
 
