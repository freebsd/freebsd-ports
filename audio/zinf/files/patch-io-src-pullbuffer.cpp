--- io/src/pullbuffer.cpp.orig	Wed Sep 17 02:35:05 2003
+++ io/src/pullbuffer.cpp	Mon Feb 16 11:42:36 2004
@@ -26,7 +26,10 @@
 #include <stdlib.h>
 #include <string.h>
 #include <assert.h>
+#include <inttypes.h>
+#if HAVE_STDINT_H
 #include <stdint.h>
+#endif
 #ifndef WIN32
 #include <unistd.h>
 #endif
