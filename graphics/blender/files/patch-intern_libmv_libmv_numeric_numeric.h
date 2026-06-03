--- intern/libmv/libmv/numeric/numeric.h.orig	2025-10-08 10:41:56 UTC
+++ intern/libmv/libmv/numeric/numeric.h
@@ -32,6 +32,7 @@
 #include <Eigen/LU>
 #include <Eigen/QR>
 #include <Eigen/SVD>
+#include <cassert>
 
 #if !defined(__MINGW64__)
 #  if defined(_WIN32) || defined(__APPLE__) || defined(__NetBSD__) ||          \
