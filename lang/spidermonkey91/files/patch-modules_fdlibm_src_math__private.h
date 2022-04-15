Index: modules/fdlibm/src/math_private.h
--- modules/fdlibm/src/math_private.h.orig	2022-03-30 19:25:49 UTC
+++ modules/fdlibm/src/math_private.h
@@ -30,7 +30,11 @@
  * Adapted from https://github.com/freebsd/freebsd-src/search?q=__double_t
  */
 
+#ifdef __i386__
+typedef long double      __double_t;
+#else
 typedef double      __double_t;
+#endif
 typedef __double_t  double_t;
 
 /*
