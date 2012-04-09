--- src/cairo-dock-menu.c.orig	2012-03-10 14:07:34.504001097 +0200
+++ src/cairo-dock-menu.c	2012-03-10 14:07:43.434017412 +0200
@@ -293,7 +293,7 @@
 			return ;
 		}
 	}
-	gchar *cCommand = g_strdup_printf ("cp '/usr/share/applications/cairo-dock%s.desktop' '%s'", (g_bForceCairo ? "-cairo" : ""), cCairoAutoStartDirPath);
+	gchar *cCommand = g_strdup_printf ("cp '/usr/local/share/applications/cairo-dock%s.desktop' '%s'", (g_bForceCairo ? "-cairo" : ""), cCairoAutoStartDirPath);
 	int r = system (cCommand);
 	g_free (cCommand);
 	g_free (cCairoAutoStartDirPath);
@@ -861,11 +861,11 @@
 	
 	// on trouve le .desktop du programme.
 	cd_debug ("%s (%s)\n", __func__, icon->cClass);
-	gchar *cDesktopFilePath = g_strdup_printf ("/usr/share/applications/%s.desktop", icon->cClass);
+	gchar *cDesktopFilePath = g_strdup_printf ("/usr/local/share/applications/%s.desktop", icon->cClass);
 	if (! g_file_test (cDesktopFilePath, G_FILE_TEST_EXISTS))  // on n'a pas trouve la, on cherche chez KDE.
 	{
 		g_free (cDesktopFilePath);
-		cDesktopFilePath = g_strdup_printf ("/usr/share/applications/kde4/%s.desktop", icon->cClass);
+		cDesktopFilePath = g_strdup_printf ("/usr/local/share/applications/kde4/%s.desktop", icon->cClass);
 		if (! g_file_test (cDesktopFilePath, G_FILE_TEST_EXISTS))  // toujours rien, on utilise locate.
 		{
 			g_free (cDesktopFilePath);
