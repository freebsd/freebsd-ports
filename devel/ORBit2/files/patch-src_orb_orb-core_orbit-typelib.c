--- src/orb/orb-core/orbit-typelib.c.orig	Fri Mar  5 23:42:33 2004
+++ src/orb/orb-core/orbit-typelib.c	Fri Mar  5 23:43:00 2004
@@ -218,6 +218,8 @@
 	paths = g_ptr_array_sized_new (8);
 
 	g_ptr_array_add (paths, g_strdup (ORBIT_TYPELIB_DIR));
+	add_if_unique(paths, "%%X11BASE%%", TRUE);
+	add_if_unique(paths, "%%LOCALBASE%%", TRUE);
 
 	if ((path = g_getenv ("ORBIT_TYPELIB_PATH"))) {
 		char **strv;
