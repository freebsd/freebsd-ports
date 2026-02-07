--- src/stlink-lib/map_file.c.orig	2025-04-02 12:31:25 UTC
+++ src/stlink-lib/map_file.c
@@ -95,7 +95,7 @@ int32_t map_file(mapped_file_t *mf, const char *path) 
     goto on_error;
   }
 
-  mf->len = (size_t)st.st_size;
+  mf->len = (uint32_t)st.st_size;
   error = 0; // success
 
 on_error:
