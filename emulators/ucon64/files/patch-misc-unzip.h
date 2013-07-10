--- misc/unzip.h.orig	2013-02-24 18:47:37.112077049 -0800
+++ misc/unzip.h	2013-02-24 18:48:46.040942781 -0800
@@ -49,6 +49,10 @@
 #include "zlib.h"
 #endif
 
+#ifndef OF
+#define OF(x) x
+#endif
+
 #if defined(STRICTUNZIP) || defined(STRICTZIPUNZIP)
 /* like the STRICT of WIN32, we define a pointer that cannot be converted
     from (void*) without cast */
