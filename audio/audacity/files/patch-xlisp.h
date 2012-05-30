--- lib-src/libnyquist/nyquist/xlisp/xlisp.h    2009-07-15 20:27:36.000000000 -0700
+++ lib-src/libnyquist/nyquist/xlisp/xlisp.h    2009-07-19 00:24:11.000000000 -0700
@@ -152,6 +152,15 @@
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
