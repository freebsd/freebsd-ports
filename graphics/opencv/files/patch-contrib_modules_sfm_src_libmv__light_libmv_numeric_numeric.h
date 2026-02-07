--- contrib/modules/sfm/src/libmv_light/libmv/numeric/numeric.h.orig	2023-12-26 21:24:58 UTC
+++ contrib/modules/sfm/src/libmv_light/libmv/numeric/numeric.h
@@ -36,7 +36,7 @@
 
 #if !defined(__MINGW32__)
 #  if defined(_WIN32) || defined(__APPLE__) || \
-      defined(__FreeBSD__) || defined(__NetBSD__)
+      defined(__NetBSD__)
 static void sincos(double x, double *sinx, double *cosx) {
   *sinx = sin(x);
   *cosx = cos(x);
