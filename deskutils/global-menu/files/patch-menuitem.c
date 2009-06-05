--- libgnomenu/menuitem.c.old	2009-06-03 12:00:59.000000000 +0200
+++ libgnomenu/menuitem.c	2009-06-03 12:01:05.000000000 +0200
@@ -128,7 +128,7 @@
 	}
 	if (_tmp0) {
 		g_debug ("menuitem.vala:81: maybe?");
-		if (gtk_menu_item_get_submenu ((GtkMenuItem*) self) != GTK_MENU (self->_submenu_cache)) {
+		if (gtk_menu_item_get_submenu ((GtkMenuItem*) self) != (GtkWidget*) GTK_MENU (self->_submenu_cache)) {
 			gtk_menu_item_set_submenu ((GtkMenuItem*) self, (GtkMenu*) self->_submenu_cache);
 		}
 	} else {
