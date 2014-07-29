--- src/GTK/Menus.C.orig	2008-09-15 17:23:52.000000000 +0000
+++ src/GTK/Menus.C	2008-09-15 17:25:14.000000000 +0000
@@ -61,7 +61,7 @@
 // Obligatory basic callback 
 void Menus::menu_callback_static(gpointer data, gpointer action, GtkWidget *w) {
   
-  switch((gint) action) {
+  switch((gulong)action) {
   case ItemFileOther:
     Menus::_interface->activate_other_player();
     gtk_widget_set_sensitive(w, FALSE);
