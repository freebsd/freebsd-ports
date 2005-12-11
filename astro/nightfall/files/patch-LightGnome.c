--- LightGnome.c.orig	Thu Oct 27 21:46:52 2005
+++ LightGnome.c	Wed Dec  7 02:44:36 2005
@@ -335,7 +335,11 @@
    FileType       *dataFile = FileList;
    char   path[256];
 
+#if 0
    argv[0] = program_invocation_name;
+#else
+   argv[0] = g_get_prgname();
+#endif
    argv[1] = "-U";
    argv[2] = NULL;
 
