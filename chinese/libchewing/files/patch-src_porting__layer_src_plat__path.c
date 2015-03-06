--- src/porting_layer/src/plat_path.c.orig	2015-02-26 14:13:31 UTC
+++ src/porting_layer/src/plat_path.c
@@ -36,10 +36,10 @@ int get_search_path(char *path, size_t p
     } else {
         home = getenv("HOME");
         if (home) {
-            snprintf(path, path_len, "%s/.chewing" SEARCH_PATH_SEP CHEWING_DATADIR "/libchewing", home);
+            snprintf(path, path_len, "%s/.chewing" SEARCH_PATH_SEP CHEWING_DATADIR, home);
         } else {
             // No HOME ?
-            strncpy(path, SEARCH_PATH_SEP CHEWING_DATADIR "/libchewing", path_len);
+            strncpy(path, SEARCH_PATH_SEP CHEWING_DATADIR, path_len);
         }
     }
 
