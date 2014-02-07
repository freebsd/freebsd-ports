--- zlib/unzip.h.orig
+++ zlib/unzip.h
@@ -49,6 +49,10 @@ extern "C" {
 #include "zlib.h"
 #endif
 
+#ifndef OF
+#define OF(a)	a
+#endif
+
 #if defined(STRICTUNZIP) || defined(STRICTZIPUNZIP)
 /* like the STRICT of WIN32, we define a pointer that cannot be converted
     from (void*) without cast */
