--- src/cong-primary-window.c.orig	Tue Dec  9 17:09:13 2003
+++ src/cong-primary-window.c	Wed Dec 10 20:16:03 2003
@@ -477,6 +477,7 @@
 	g_assert (primary_window);
 
 	if (doc) {
+		gchar *status_text;
 		primary_window->doc = doc;
 		g_object_ref(G_OBJECT(doc));
 		LOG_PRIMARY_WINDOW_CREATION1 ("Creating v3 widget");
@@ -562,7 +563,7 @@
 		
 		/* update the statusbar */
 		
-		gchar *status_text = g_strdup(cong_dispspec_get_name( cong_document_get_dispspec(primary_window->doc) ));
+		status_text = g_strdup(cong_dispspec_get_name( cong_document_get_dispspec(primary_window->doc) ));
 #if 1
 		gnome_appbar_set_status (GNOME_APPBAR(primary_window->app_bar), 
 			 status_text);
