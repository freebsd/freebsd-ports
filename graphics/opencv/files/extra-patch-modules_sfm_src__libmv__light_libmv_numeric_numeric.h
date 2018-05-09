--- modules/sfm/src/libmv_light/libmv/numeric/numeric.h.orig	2017-12-22 19:15:17.000000000 +0300
+++ modules/sfm/src/libmv_light/libmv/numeric/numeric.h	2018-01-15 01:06:23.742535000 +0300
@@ -35,7 +35,7 @@
 
 #if !defined(__MINGW64__)
 #  if defined(_WIN32) || defined(__APPLE__) || \
-      defined(__FreeBSD__) || defined(__NetBSD__)
+      defined(__NetBSD__)
 static void sincos(double x, double *sinx, double *cosx) {
   *sinx = sin(x);
   *cosx = cos(x);
