--- intern/libmv/libmv/numeric/numeric.h.orig	2017-02-24 14:09:19.000000000 +0000
+++ intern/libmv/libmv/numeric/numeric.h	2017-07-12 22:13:26.065072000 +0000
@@ -33,9 +33,13 @@
 #include <Eigen/QR>
 #include <Eigen/SVD>
 
+#if defined(__FreeBSD__)
+#include <osreldate.h>
+#endif
+
 #if !defined(__MINGW64__)
 #  if defined(_WIN32) || defined(__APPLE__) || \
-      defined(__FreeBSD__) || defined(__NetBSD__)
+      (defined(__FreeBSD__) && __FreeBSD_version < 1200032) || defined(__NetBSD__)
 static void sincos(double x, double *sinx, double *cosx) {
   *sinx = sin(x);
   *cosx = cos(x);
