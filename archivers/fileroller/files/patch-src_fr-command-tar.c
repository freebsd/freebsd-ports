--- src/fr-command-tar.c.orig	Sun Feb 20 17:17:15 2005
+++ src/fr-command-tar.c	Sun Feb 20 17:19:07 2005
@@ -219,7 +219,7 @@
 	/* In solaris gtar is present under /usr/sfw/bin */
 
 	prev_path = g_getenv ("PATH");
-	temp = g_strdup_printf ("PATH=%s:%s", prev_path, "/usr/sfw/bin");
+	temp = g_strdup_printf ("PATH=%s:%s:%s", "%%LOCALBASE%%/bin", prev_path, "/usr/sfw/bin");
 	putenv (temp);
 
 	path = g_find_program_in_path ("gtar");
