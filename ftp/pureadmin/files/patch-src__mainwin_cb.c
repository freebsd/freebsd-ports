--- src/mainwin_cb.c.orig	Tue Nov 15 20:21:22 2005
+++ src/mainwin_cb.c	Sat Nov 26 20:32:20 2005
@@ -357,6 +357,9 @@
 {
 	gchar *browser = misc_find_webbrowser();
 	GError *err = NULL;
+	gchar *quoted_url = g_shell_quote (url);
+	gchar *cmd = g_strdup_printf (browser, quoted_url);
+	gboolean success;
 	if (!browser) {
 		gchar *msg = g_strdup_printf (_("The default browser could not be located. You can solve this "
 					      "by either:\n"
@@ -369,10 +372,7 @@
 		g_free (msg);
 		return;
 	}
-	gchar *quoted_url = g_shell_quote (url);
-	gchar *cmd = g_strdup_printf (browser, quoted_url);
 	pur_log_dbg ("Running: %s", cmd);
-	gboolean success;
 	
 	success = g_spawn_command_line_async (cmd, &err);
 	//success = FALSE;
