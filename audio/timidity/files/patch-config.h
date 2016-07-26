--- config.h.orig	1996-06-01 12:54:49 UTC
+++ config.h
@@ -217,6 +217,22 @@
 # endif
 #endif /* linux */
 
+#ifdef __FreeBSD__
+#include <errno.h>
+#include <machine/endian.h>
+#if BYTE_ORDER == LITTLE_ENDIAN
+#undef BIG_ENDIAN
+#undef PDP_ENDIAN
+#elif BYTE_ORDER == BIG_ENDIAN
+#undef LITTLE_ENDIAN
+#undef PDP_ENDIAN
+#else
+# error No valid byte sex defined
+#endif
+#define USE_LDEXP
+#define PI M_PI
+#endif
+
 /* Win32 on Intel machines */
 #ifdef __WIN32__
 #  define LITTLE_ENDIAN
