Index: gnome-initial-setup/pages/keyboard/gis-keyboard-page.c
--- gnome-initial-setup/pages/keyboard/gis-keyboard-page.c.orig	2022-12-02 15:11:34 UTC
+++ gnome-initial-setup/pages/keyboard/gis-keyboard-page.c
@@ -195,14 +195,16 @@ update_input (GisKeyboardPage *self)
 
 	set_input_settings (self);
 
-	if (gis_driver_get_mode (GIS_PAGE (self)->driver) == GIS_DRIVER_MODE_NEW_USER) {
-		if (g_permission_get_allowed (priv->permission)) {
-			set_localed_input (self);
-		} else if (g_permission_get_can_acquire (priv->permission)) {
-			g_permission_acquire_async (priv->permission,
-						    NULL,
-						    change_locale_permission_acquired,
-						    self);
+	if (priv->permission != NULL) {
+		if (gis_driver_get_mode (GIS_PAGE (self)->driver) == GIS_DRIVER_MODE_NEW_USER) {
+			if (g_permission_get_allowed (priv->permission)) {
+				set_localed_input (self);
+			} else if (g_permission_get_can_acquire (priv->permission)) {
+				g_permission_acquire_async (priv->permission,
+							    NULL,
+							    change_locale_permission_acquired,
+							    self);
+			}
 		}
 	}
 }
