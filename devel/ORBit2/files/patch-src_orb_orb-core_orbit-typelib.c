--- src/orb/orb-core/orbit-typelib.c.orig	Sun May 11 20:37:14 2003
+++ src/orb/orb-core/orbit-typelib.c	Sun May 11 20:40:42 2003
@@ -215,6 +215,8 @@
 	paths = g_ptr_array_sized_new (8);
 
 	g_ptr_array_add (paths, g_strdup (ORBIT_TYPELIB_DIR));
+	add_if_unique(paths, "%%X11BASE%%", TRUE);
+	add_if_unique(paths, "%%LOCALBASE%%", TRUE);
 
 	if ((path = g_getenv ("ORBIT_TYPELIB_PATH"))) {
 		char **strv;
