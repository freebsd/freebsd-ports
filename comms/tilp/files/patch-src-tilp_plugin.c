--- src/tilp_plugin.c.orig	Mon Feb 14 18:53:16 2005
+++ src/tilp_plugin.c	Mon Feb 14 18:54:11 2005
@@ -171,6 +171,7 @@
 	printl(0, _("Done !\n"));
 
 	// Scan registry 
+#ifndef __BSD__
 	printl(0, _("scanning registry... "));
 #ifdef __WIN32__
 	reg_fn = g_strconcat(inst_paths.base_dir, REG_FILE, NULL);
@@ -231,6 +232,7 @@
 	}
 	fclose(reg);
 	printl(0, _("Done !\n"));
+#endif
 
 	return 0;
 }
