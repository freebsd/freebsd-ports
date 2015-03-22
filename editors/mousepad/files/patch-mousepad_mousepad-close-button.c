--- mousepad/mousepad-close-button.c.orig	2014-09-01 20:50:07 UTC
+++ mousepad/mousepad-close-button.c
@@ -88,7 +88,7 @@ mousepad_close_button_init (MousepadClos
   gtk_widget_set_name (GTK_WIDGET (button), "mousepad-close-button");
 #endif
 
-  image = gtk_image_new_from_icon_name ("gtk-close", GTK_ICON_SIZE_MENU);
+  image = gtk_image_new_from_icon_name ("window-close", GTK_ICON_SIZE_MENU);
   gtk_container_add (GTK_CONTAINER (button), image);
   gtk_widget_show (image);
 
