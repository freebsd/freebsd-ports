--- mono/metadata/assembly.c.orig	Tue May  3 15:42:51 2005
+++ mono/metadata/assembly.c	Thu May  5 17:34:31 2005
@@ -174,7 +174,8 @@
 	const char *path;
 	char **splitted;
 	
-	path = g_getenv ("MONO_GAC_PREFIX");
+	path = g_strjoin(G_SEARCHPATH_SEPARATOR_S, "%%X11BASE%%", g_getenv("MONO_GAC_PREFIX"), NULL);
+
 	if (!path)
 		return;
 
