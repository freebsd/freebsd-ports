Partial application of upstream commit c8fc656, closing
upstream bug #985 and #1175 and fixing the build on 32
bit platforms.

https://github.com/stlink-org/stlink/commit/c8fc6561fead79ad49c09d82bab864745086792c
https://github.com/stlink-org/stlink/issues/985
https://github.com/stlink-org/stlink/issues/1175

--- src/common.c.orig	2021-04-24 22:24:02 UTC
+++ src/common.c
@@ -1,4 +1,5 @@
 #define DEBUG_FLASH 0
+#include <limits.h>
 #include <stdarg.h>
 #include <stdint.h>
 #include <stdio.h>
@@ -2205,7 +2206,7 @@ static int map_file(mapped_file_t *mf, const char *pat
 
   if (sizeof(st.st_size) != sizeof(size_t)) {
     // on 32 bit systems, check if there is an overflow
-    if (st.st_size > (off_t)INT32_MAX) {
+    if (st.st_size > (off_t)SSIZE_MAX) {
       fprintf(stderr, "mmap() size_t overflow for file %s\n", path);
       goto on_error;
     }
@@ -2219,7 +2220,7 @@ static int map_file(mapped_file_t *mf, const char *pat
     goto on_error;
   }
 
-  mf->len = st.st_size;
+  mf->len = (size_t)st.st_size;
   error = 0; // success
 
 on_error:
