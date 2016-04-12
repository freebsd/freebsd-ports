--- src/GTK/Menus.C.orig	1999-05-12 01:51:42 UTC
+++ src/GTK/Menus.C
@@ -61,7 +61,7 @@ GtkInterface * Menus::_interface;
 // Obligatory basic callback 
 void Menus::menu_callback_static(gpointer data, gpointer action, GtkWidget *w) {
   
-  switch((gint) action) {
+  switch((gulong)action) {
   case ItemFileOther:
     Menus::_interface->activate_other_player();
     gtk_widget_set_sensitive(w, FALSE);
