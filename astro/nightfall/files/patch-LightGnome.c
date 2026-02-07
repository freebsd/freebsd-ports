--- LightGnome.c.orig	2011-11-18 12:47:36 UTC
+++ LightGnome.c
@@ -333,7 +333,11 @@ gint
    FileType       *dataFile = FileList;
    char   path[256];
 
+#if 0
    argv[0] = program_invocation_name;
+#else
+   argv[0] = g_get_prgname();
+#endif
    argv[1] = "-U";
    argv[2] = NULL;
 
