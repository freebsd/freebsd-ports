--- io/src/pullbuffer.cpp.orig	2003-09-16 17:35:05 UTC
+++ io/src/pullbuffer.cpp
@@ -26,7 +26,10 @@ ________________________________________
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
