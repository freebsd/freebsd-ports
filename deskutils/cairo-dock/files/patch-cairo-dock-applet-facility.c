--- src/gldit/cairo-dock-applet-facility.c.orig	2012-04-08 11:31:10.000000000 +0300
+++ src/gldit/cairo-dock-applet-facility.c	2012-04-08 11:32:21.000000000 +0300
@@ -350,13 +350,13 @@
 	
 	GError *erreur = NULL;
 	gchar *cSoundCommand = NULL;
-	if (g_file_test ("/usr/bin/paplay", G_FILE_TEST_EXISTS))
+	if (g_file_test ("/usr/local/bin/paplay", G_FILE_TEST_EXISTS))
 		cSoundCommand = g_strdup_printf("paplay --client-name=cairo-dock \"%s\"", cSoundPath);
 
 	else if (g_file_test ("/usr/bin/aplay", G_FILE_TEST_EXISTS))
 		cSoundCommand = g_strdup_printf("aplay \"%s\"", cSoundPath);
 
-	else if (g_file_test ("/usr/bin/play", G_FILE_TEST_EXISTS))
+	else if (g_file_test ("/usr/local/bin/play", G_FILE_TEST_EXISTS))
 		cSoundCommand = g_strdup_printf("play \"%s\"", cSoundPath);
 	
 	
