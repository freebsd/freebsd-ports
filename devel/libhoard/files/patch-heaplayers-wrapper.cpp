--- heaplayers/wrapper.cpp.orig	Thu May 24 10:24:34 2007
+++ heaplayers/wrapper.cpp	Thu May 24 10:29:14 2007
@@ -31,7 +31,11 @@
  */
 
 #include <string.h> // for memcpy
+#ifdef __FreeBSD__
+#include <stdlib.h>
+#else
 #include <malloc.h> // for memalign
+#endif
 
 #ifdef _WIN32
 #define WIN32_LEAN_AND_MEAN
