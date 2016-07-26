--- cmp3main.c.orig	2001-07-07 19:17:23 UTC
+++ cmp3main.c
@@ -33,13 +33,18 @@ int main(int argc, char **argv)
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
