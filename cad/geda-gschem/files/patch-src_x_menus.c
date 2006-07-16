--- src/x_menus.c.orig	Thu Jul 13 14:21:07 2006
+++ src/x_menus.c	Thu Jul 13 14:21:49 2006
@@ -284,9 +284,11 @@
    */
   item_factory = gtk_item_factory_new(GTK_TYPE_MENU, "<popup>",
 				      accel_group);
+#if defined(ENABLE_NLS)
   gtk_item_factory_set_translate_func(item_factory,
 				      (GtkTranslateFunc) gettext,
 				      NULL, NULL);
+#endif
   /* This function creates the pop-up menu itself & attaches it to the
      GtkItemFactory. Pass the item factory,
      the number of items in the array, the array itself, and any
