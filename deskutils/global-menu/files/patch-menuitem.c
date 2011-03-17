--- libserver/widgets/menuitem.c.orig	2010-11-29 16:07:02.000000000 +0200
+++ libserver/widgets/menuitem.c	2010-11-29 16:07:09.000000000 +0200
@@ -358,7 +358,7 @@
 		_tmp0_ = FALSE;
 	}
 	if (_tmp0_) {
-		if (gtk_menu_item_get_submenu ((GtkMenuItem*) self) != GTK_MENU (self->_submenu_cache)) {
+		if (gtk_menu_item_get_submenu ((GtkMenuItem*) self) != (GtkWidget*) GTK_MENU (self->_submenu_cache)) {
 			gtk_menu_item_set_submenu ((GtkMenuItem*) self, (GtkMenu*) self->_submenu_cache);
 		}
 	} else {
