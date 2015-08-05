$OpenBSD: patch-gnome-initial-setup_pages_keyboard_cc-input-chooser_c,v 1.1 2014/04/07 10:30:32 a

gnome-initial-setup in free(): error: bogus pointer

--- gnome-initial-setup/pages/keyboard/cc-input-chooser.c.orig	2015-03-13 22:00:44.000000000 +0100
+++ gnome-initial-setup/pages/keyboard/cc-input-chooser.c	2015-05-14 07:45:27.366059000 +0200
@@ -404,6 +404,8 @@
 	gchar *lang, *country;
 	GList *list;
 
+	lang = country = NULL;
+
 	if (gnome_get_input_source_from_locale (priv->locale, &type, &id)) {
                 add_row_to_list (chooser, type, id);
 		if (!priv->id) {
