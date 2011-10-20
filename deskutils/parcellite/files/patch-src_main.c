--- src/main.c.orig	2011-10-18 08:06:24.000000000 +0800
+++ src/main.c	2011-10-18 08:07:17.000000000 +0800
@@ -1010,9 +1010,10 @@
   gtk_menu_shell_append((GtkMenuShell*)menu, gtk_separator_menu_item_new());
   /* Clear */
 	if(0 ==prefs.type_search){
-  menu_item = gtk_image_menu_item_new_with_label(_("Clear"));
+  menu_item = gtk_image_menu_item_new_with_mnemonic(_("Clear"));
   menu_image = gtk_image_new_from_stock(GTK_STOCK_CLEAR, GTK_ICON_SIZE_MENU);
   gtk_image_menu_item_set_image((GtkImageMenuItem*)menu_item, menu_image);
+  g_signal_connect((GObject*)menu_item, "activate", (GCallback)clear_selected, NULL);
   gtk_menu_shell_append((GtkMenuShell*)menu, menu_item);
   }  
   /* Popup the menu... */
