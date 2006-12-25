--- src/gimv_thumb_win.c.orig	Mon Dec 20 19:18:30 2004
+++ src/gimv_thumb_win.c	Mon Dec 25 22:03:12 2006
@@ -1219,7 +1219,9 @@
 }
 
 
+#if 0
 #warning should be implemented as customizable launcher.
+#endif
 static void
 cb_wallpaper_setting (GtkWidget *menuitem, GimvThumbWin *tw)
 {
@@ -2542,9 +2544,12 @@
 {
    if (tw && tw->priv)
       tw->priv->slideshow_selected_only
+#ifdef USE_GTK2
          = gtk_check_menu_item_get_active (GTK_CHECK_MENU_ITEM (widget));
+#else /* USE_GTK2 */
+         = GTK_CHECK_MENU_ITEM (widget)->active;
+#endif /* USE_GTK2 */
 }
-
 
 static void
 cb_slideshow_file_type (GimvThumbWin *tw, SlideShowFileType action,
