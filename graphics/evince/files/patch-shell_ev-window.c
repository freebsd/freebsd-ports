--- shell/ev-window.c.orig	2010-07-05 20:36:07.000000000 -0400
+++ shell/ev-window.c	2010-07-05 20:36:10.000000000 -0400
@@ -6107,7 +6107,7 @@ ev_window_create_last_settings_metadata 
 	GFile *file;
 	gchar *path;
 
-	path = g_build_filename (ev_application_get_dot_dir (EV_APP, FALSE), "last_settings", NULL);
+	path = g_build_filename (ev_application_get_dot_dir (EV_APP, TRUE), "last_settings", NULL);
 	file = g_file_new_for_path (path);
 	g_free (path);
 
