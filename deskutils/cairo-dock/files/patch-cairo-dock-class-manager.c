--- src/gldit/cairo-dock-class-manager.c.orig	2012-03-10 14:05:52.663999155 +0200
+++ src/gldit/cairo-dock-class-manager.c	2012-03-10 14:06:17.963989866 +0200
@@ -1189,13 +1189,13 @@
 {
 	gboolean bFound = TRUE;
 	GString *sDesktopFilePath = g_string_new ("");
-	g_string_printf (sDesktopFilePath, "/usr/share/applications/%s.desktop", cClass);
+	g_string_printf (sDesktopFilePath, "/usr/local/share/applications/%s.desktop", cClass);
 	if (! g_file_test (sDesktopFilePath->str, G_FILE_TEST_EXISTS))
 	{
-		g_string_printf (sDesktopFilePath, "/usr/share/applications/xfce4/%s.desktop", cClass);
+		g_string_printf (sDesktopFilePath, "/usr/local/share/applications/xfce4/%s.desktop", cClass);
 		if (! g_file_test (sDesktopFilePath->str, G_FILE_TEST_EXISTS))
 		{
-			g_string_printf (sDesktopFilePath, "/usr/share/applications/kde4/%s.desktop", cClass);
+			g_string_printf (sDesktopFilePath, "/usr/local/share/applications/kde4/%s.desktop", cClass);
 			if (! g_file_test (sDesktopFilePath->str, G_FILE_TEST_EXISTS))
 			{
 				bFound = FALSE;
