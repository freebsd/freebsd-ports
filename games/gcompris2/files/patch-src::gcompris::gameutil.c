--- src/gcompris/gameutil.c.orig	Sun Mar  7 17:36:56 2004
+++ src/gcompris/gameutil.c	Sun Mar  7 17:37:28 2004
@@ -121,9 +121,11 @@
   filename = g_strdup_printf("%s/%s", PACKAGE_DATA_DIR, pixmapfile);
 
   if (!g_file_test ((filename), G_FILE_TEST_EXISTS)) {
+    char *str;
+
     g_warning (_("Couldn't find file %s !"), filename);
 
-    char *str = g_strdup_printf("%s\n%s\n%s\n%s", 
+    str = g_strdup_printf("%s\n%s\n%s\n%s", 
 				_("Couldn't find file"), 
 				pixmapfile,
 				_("This activity is incomplete."),
