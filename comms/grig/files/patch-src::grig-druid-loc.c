--- src/grig-druid-loc.c.orig	Sun May  9 07:18:50 2004
+++ src/grig-druid-loc.c	Sun May  9 07:16:04 2004
@@ -293,9 +293,9 @@
 	*/
 	if (gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON (radll))) {
 		longlat2locator (g_strtod (gtk_entry_get_text (GTK_ENTRY (lonwdg)), NULL),
 				 g_strtod (gtk_entry_get_text (GTK_ENTRY (latwdg)), NULL),
-				 loc);
+				 loc, 3);
 		gtk_entry_set_text (GTK_ENTRY (locatorwdg), g_strdup (loc));
 	}
 #endif
 }
