--- src/orb/orb-core/orbit-typelib.c.orig	2007-07-27 10:58:37.000000000 -0500
+++ src/orb/orb-core/orbit-typelib.c	2007-07-27 10:58:41.000000000 -0500
@@ -218,6 +218,7 @@
 	paths = g_ptr_array_sized_new (8);
 
 	g_ptr_array_add (paths, g_strdup (ORBIT_TYPELIB_DIR));
+	add_if_unique(paths, "%%LOCALBASE%%", TRUE);
 
 	if ((path = g_getenv ("ORBIT_TYPELIB_PATH"))) {
 		char **strv;
