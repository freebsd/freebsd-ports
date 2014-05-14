$OpenBSD: patch-gnome-initial-setup_pages_keyboard_cc-input-chooser_c,v 1.1 2014/04/07 10:30:32 ajacoutot Exp $

gnome-initial-setup in free(): error: bogus pointer

--- gnome-initial-setup/pages/keyboard/cc-input-chooser.c.orig	Mon Mar 10 05:47:29 2014
+++ gnome-initial-setup/pages/keyboard/cc-input-chooser.c	Mon Apr  7 12:20:04 2014
@@ -366,6 +366,8 @@ get_locale_infos (CcInputChooser *chooser)
 	gchar *lang, *country;
 	GList *list;
 
+	lang = country = NULL;
+
 	if (gnome_get_input_source_from_locale (priv->locale, &type, &id)) { 
 		if (g_str_equal (type, INPUT_SOURCE_TYPE_XKB))
 			add_row_to_list (chooser, type, id);
@@ -575,6 +577,8 @@ get_ibus_locale_infos (CcInputChooser *chooser)
 	const gchar *engine_id;
 	IBusEngineDesc *engine;
 	gchar *lang, *country;
+
+	lang = country = NULL;
 
 	if (!priv->ibus_engines)
 		return;
