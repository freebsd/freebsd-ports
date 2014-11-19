$OpenBSD: patch-gnome-initial-setup_pages_keyboard_gis-keyboard-page_c,v 1.1 2014/04/07 10:30:32 ajacoutot Exp $
--- gnome-initial-setup/pages/keyboard/gis-keyboard-page.c.orig	Mon Apr  7 11:02:37 2014
+++ gnome-initial-setup/pages/keyboard/gis-keyboard-page.c	Mon Apr  7 11:03:32 2014
@@ -128,14 +128,16 @@ update_input (GisKeyboardPage *self)
 
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
