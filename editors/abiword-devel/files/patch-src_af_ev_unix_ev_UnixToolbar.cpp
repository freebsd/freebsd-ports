--- src/af/ev/unix/ev_UnixToolbar.cpp.orig	Mon Mar 24 01:55:52 2003
+++ src/af/ev/unix/ev_UnixToolbar.cpp	Mon Mar 24 01:51:14 2003
@@ -881,11 +881,11 @@
 			    GtkWidget * combo;
 				GdkPixbuf * pixbuf;
 			    if (pAction->getItemType() == EV_TBIT_ColorFore) {
-					pixbuf = gdk_pixbuf_new_from_xpm_data (static_cast<const char **>(tb_text_fgcolor_xpm));
+					pixbuf = gdk_pixbuf_new_from_xpm_data (static_cast<char **>(tb_text_fgcolor_xpm));
 					combo = color_combo_new (pixbuf, szToolTip, &e_black, color_group_fetch("foreground_color", NULL));
 			    }
 				else {
-					pixbuf = gdk_pixbuf_new_from_xpm_data (static_cast<const char **>(tb_text_bgcolor_xpm));
+					pixbuf = gdk_pixbuf_new_from_xpm_data (static_cast<char **>(tb_text_bgcolor_xpm));
 					combo = color_combo_new (pixbuf, szToolTip, NULL, color_group_fetch("background_color", NULL));
 				}
 			    gtk_combo_box_set_title (GTK_COMBO_BOX (combo),
