$OpenBSD: patch-gnome-initial-setup_pages_region_gis-region-page_c,v 1.1 2014/04/07 10:30:32 ajacoutot Exp $
--- gnome-initial-setup/pages/region/gis-region-page.c.orig	Mon Apr  7 11:02:42 2014
+++ gnome-initial-setup/pages/region/gis-region-page.c	Mon Apr  7 11:04:03 2014
@@ -123,15 +123,17 @@ region_changed (CcRegionChooser  *chooser,
   setlocale (LC_MESSAGES, priv->new_locale_id);
   gis_driver_locale_changed (driver);
 
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
   user = act_user_manager_get_user (act_user_manager_get_default (),
