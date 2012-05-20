--- src/sj-main.c.orig	2012-02-14 16:44:03.000000000 +0900
+++ src/sj-main.c	2012-02-14 16:46:41.000000000 +0900
@@ -410,9 +410,11 @@
   g_return_val_if_fail (title != NULL, NULL);
   g_return_val_if_fail (artist != NULL, NULL);
 
-  infobar = gtk_info_bar_new_with_buttons (_("S_ubmit Album"), GTK_RESPONSE_OK,
-                                           GTK_STOCK_CANCEL, GTK_RESPONSE_CANCEL,
-                                           NULL);
+  infobar = gtk_info_bar_new ();
+  button = gtk_info_bar_add_button (GTK_INFO_BAR (infobar),
+                                    _("S_ubmit Album"), GTK_RESPONSE_OK);
+  gtk_info_bar_add_button (GTK_INFO_BAR (infobar),
+                           GTK_STOCK_CANCEL, GTK_RESPONSE_CANCEL);
 
   /* Translators: title, artist */
   primary_text = g_strdup_printf (_("Could not find %s by %s on MusicBrainz."), title, artist);
