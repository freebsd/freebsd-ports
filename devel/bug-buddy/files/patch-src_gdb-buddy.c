--- src/gdb-buddy.c.orig	2010-11-16 18:43:48.000000000 +0100
+++ src/gdb-buddy.c	2010-11-16 18:54:28.000000000 +0100
@@ -170,7 +170,7 @@
 	link = g_strdup_printf ("/proc/%d/path/a.out", pid);
 #else
 	/* if someone knows how to do this on BSD, please send a patch */
-	return NULL;
+	link = g_file_read_link ("/proc/curproc/file", NULL);
 #endif
 	exe = g_file_read_link (link, &error);
 
