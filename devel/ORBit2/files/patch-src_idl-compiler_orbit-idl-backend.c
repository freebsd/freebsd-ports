--- src/idl-compiler/orbit-idl-backend.c.orig	Tue Oct  1 23:32:46 2002
+++ src/idl-compiler/orbit-idl-backend.c	Sun May 11 20:51:19 2003
@@ -38,6 +38,8 @@
 	char **strv;
 	int    i;
 
+	paths = g_slist_prepend (paths, "%%X11BASE%%/lib/orbit-2.0/idl-backends");
+
 	if (!(val = getenv ("GNOME2_PATH")))
 		return paths;
 
