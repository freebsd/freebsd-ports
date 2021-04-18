--- lib-src/libnyquist/nyquist/xlisp/xlfio.c.orig	2021-02-04 18:52:51 UTC
+++ lib-src/libnyquist/nyquist/xlisp/xlfio.c
@@ -19,8 +19,7 @@
 /* do some sanity checking: */
 #ifndef XL_BIG_ENDIAN
 #ifndef XL_LITTLE_ENDIAN
-#error configuration error -- either XL_BIG_ or XL_LITTLE_ENDIAN must be defined
-in xlisp.h
+#error configuration error -- either XL_BIG_ or XL_LITTLE_ENDIAN must be defined in xlisp.h
 #endif
 #endif
 #ifdef XL_BIG_ENDIAN
