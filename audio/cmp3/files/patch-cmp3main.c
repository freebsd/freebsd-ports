--- cmp3main.c.orig	2001-07-07 16:17:23.000000000 -0300
+++ cmp3main.c	2009-09-20 11:11:06.000000000 -0300
@@ -33,13 +33,18 @@
     int         lastleftline = 0;
     int         lastrightline = 0;
     char       *init_dir = NULL;
+    char       *home_dir = NULL;
+    char       cmp3_config[4096];
 
     if (argc > 1)
         docmdline(argc, argv);
     shm_init();
 
     cmp3rc = ini_create();
-    if (ini_load(cmp3rc, CMP3_CONFIG) == INI_FAIL)
+    home_dir = getenv("HOME");
+    strcpy (cmp3_config, home_dir);
+    strcat (cmp3_config, "/.cmp3rc");
+    if (ini_load(cmp3rc, cmp3_config) == INI_FAIL)
     {
         ini_destroy(cmp3rc);
         cmp3rc = NULL;
