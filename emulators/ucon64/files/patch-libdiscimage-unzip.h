--- libdiscmage/unzip.h.orig	2013-02-24 18:48:58.073946338 -0800
+++ libdiscmage/unzip.h	2013-02-24 18:50:15.451943149 -0800
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
