--- mono/metadata/assembly.c.orig	Mon Sep  6 13:06:56 2004
+++ mono/metadata/assembly.c	Sat Oct 30 02:40:05 2004
@@ -100,7 +100,8 @@
 	const char *path;
 	char **splitted;
 	
-	path = g_getenv ("MONO_GAC_PREFIX");
+	path = g_strjoin(G_SEARCHPATH_SEPARATOR_S, "%%X11BASE%%", g_getenv("MONO_GAC_PREFIX"), NULL);
+
 	if (!path)
 		return;
 
