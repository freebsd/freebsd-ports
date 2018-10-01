--- lib-src/libnyquist/nyquist/xlisp/xlisp.h.orig	2016-07-26 13:34:06 UTC
+++ lib-src/libnyquist/nyquist/xlisp/xlisp.h
@@ -160,6 +160,15 @@ extern long ptrtoabs();
 #endif
 #endif
 
+/* FreeBSD */
+#ifdef __FreeBSD__
+#if __BYTE_ORDER == __LITTLE_ENDIAN
+#define XL_LITTLE_ENDIAN
+#else
+#define XL_BIG_ENDIAN
+#endif
+#endif
+
 /* Apple CC */
 #ifdef __APPLE__
 #define NNODES 2000
