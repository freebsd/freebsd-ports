--- intern/slim/intern/uv_initializer.h.orig	2025-10-08 10:41:56 UTC
+++ intern/slim/intern/uv_initializer.h
@@ -11,6 +11,8 @@
 #include <Eigen/Dense>
 #include <Eigen/Sparse>
 
+#include <cassert>
+
 enum Method { TUTTE, HARMONIC, MVC };
 
 namespace slim {
