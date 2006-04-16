--- server/gtk/main.c.orig	Sun Apr 16 17:32:07 2006
+++ server/gtk/main.c	Sun Apr 16 17:33:14 2006
@@ -193,6 +193,7 @@
 
 static void gui_set_server_state(gboolean running)
 {
+	gchar *fullname;
 	gboolean ai_settings_enabled = TRUE;
 
 	is_running = running;
@@ -215,7 +216,7 @@
 			     running ? _("Stop the server") :
 			     _("Start the server"), NULL);
 
-	gchar *fullname = g_find_program_in_path(PIONEERS_AI_PATH);
+	fullname = g_find_program_in_path(PIONEERS_AI_PATH);
 	if (fullname) {
 		g_free(fullname);
 	} else {
