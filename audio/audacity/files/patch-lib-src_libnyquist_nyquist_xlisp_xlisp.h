--- lib-src/libnyquist/nyquist/xlisp/xlisp.h.orig	2021-02-04 18:52:51 UTC
+++ lib-src/libnyquist/nyquist/xlisp/xlisp.h
@@ -172,6 +172,15 @@ extern long ptrtoabs();
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
 /* Apple CC (xcode, macOS, macintosh) */
 #ifdef __APPLE__
 #define NNODES 2000
