--- src/tilp_plugin.c.orig	Wed Apr 23 20:51:57 2003
+++ src/tilp_plugin.c	Thu Apr 24 13:33:41 2003
@@ -168,6 +168,7 @@
 	g_dir_close(dir);
 	DISPLAY(_("Done !\n"));
 
+#ifndef __BSD__
 	// Scan registry 
 	DISPLAY(_("Scanning registry... "));
 #ifdef __WIN32__
@@ -229,7 +230,7 @@
 	}
 	fclose(reg);
 	DISPLAY(_("Done !\n"));
-
+#endif
 	return 0;
 }
 
