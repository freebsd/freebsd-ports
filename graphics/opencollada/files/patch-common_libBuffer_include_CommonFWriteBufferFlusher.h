--- common/libBuffer/include/CommonFWriteBufferFlusher.h.orig	2013-11-16 10:47:19.000000000 +0100
+++ common/libBuffer/include/CommonFWriteBufferFlusher.h	2013-11-16 10:47:48.000000000 +0100
@@ -35,6 +35,9 @@
 #ifdef __GNUC__
 #   include <cstdlib> /* size_t */
 #   include <cstdio>  /* FILE */
+#ifdef __FreeBSD__
+#include <stdint.h> /* int64_t */
+#endif
 #endif
 
 #if (defined(__GNUC__) && !defined(__STRICT_ANSI__) && !defined(__MINGW32__)) || (__STDC_VERSION__ >= 199901L)
