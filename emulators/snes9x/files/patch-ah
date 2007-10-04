--- unzip/unzip.h	2007-10-03 12:28:47.000000000 -0500
+++ unzip/unzip.h	2007-10-03 12:30:22.000000000 -0500
@@ -41,14 +41,18 @@
 #ifndef _unz_H
 #define _unz_H
 
-#ifdef __cplusplus
-extern "C" {
-#endif
+#include <sys/types.h>
 
 #ifndef _ZLIB_H
 #include <zlib.h>
 #endif
 
+#ifdef __cplusplus
+extern "C" {
+#endif
+
+#define ZEXPORT
+
 #if defined(STRICTUNZIP) || defined(STRICTZIPUNZIP)
 /* like the STRICT of WIN32, we define a pointer that cannot be converted
     from (void*) without cast */
