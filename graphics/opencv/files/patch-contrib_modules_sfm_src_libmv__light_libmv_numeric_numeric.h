--- contrib/modules/sfm/src/libmv_light/libmv/numeric/numeric.h.orig	2021-01-30 07:20:50 UTC
+++ contrib/modules/sfm/src/libmv_light/libmv/numeric/numeric.h
@@ -35,7 +35,7 @@
 
 #if !defined(__MINGW64__)
 #  if defined(_WIN32) || defined(__APPLE__) || \
-      defined(__FreeBSD__) || defined(__NetBSD__)
+      defined(__NetBSD__)
 static void sincos(double x, double *sinx, double *cosx) {
   *sinx = sin(x);
   *cosx = cos(x);
