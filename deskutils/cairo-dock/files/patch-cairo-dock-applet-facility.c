--- ./src/gldit/cairo-dock-applet-facility.c.orig	2013-06-29 16:54:06.000000000 +0300
+++ ./src/gldit/cairo-dock-applet-facility.c	2013-06-29 16:55:44.000000000 +0300
@@ -225,14 +225,14 @@
 	}
 	
 	gchar *cSoundCommand = NULL;
-	if (g_file_test ("/usr/bin/paplay", G_FILE_TEST_EXISTS))
-		cSoundCommand = g_strdup_printf("paplay --client-name=cairo-dock \"%s\"", cSoundPath);
+	if (g_file_test ("%%LOCALBASE%%/bin/play", G_FILE_TEST_EXISTS))
+		cSoundCommand = g_strdup_printf("play \"%s\"", cSoundPath);
 
-	else if (g_file_test ("/usr/bin/aplay", G_FILE_TEST_EXISTS))
+	else if (g_file_test ("%%LOCALBASE%%/bin/paplay", G_FILE_TEST_EXISTS))
+		cSoundCommand = g_strdup_printf("paplay --client-name=cairo-dock \"%s\"", cSoundPath);
+	
+	else if (g_file_test ("%%LOCALBASE%%/bin/aplay", G_FILE_TEST_EXISTS))
 		cSoundCommand = g_strdup_printf("aplay \"%s\"", cSoundPath);
-
-	else if (g_file_test ("/usr/bin/play", G_FILE_TEST_EXISTS))
-		cSoundCommand = g_strdup_printf("play \"%s\"", cSoundPath);
 	
 	
 	cairo_dock_launch_command (cSoundCommand);
