--- source/shared_lib/include/graphics/math_util.h.orig	2022-12-31 03:15:04 UTC
+++ source/shared_lib/include/graphics/math_util.h
@@ -23,6 +23,16 @@ const float sqrt2= 1.41421356f;
 const float zero= 1e-6f;
 const float infinity= 1e6f;
 
+template <typename T>
+inline T max(const T& a, const T& b) {
+   return (b > a) ? b : a;
+}
+
+template <typename T>
+inline T min(const T& a, const T& b) {
+   return (b < a) ? b : a;
+}
+
 // =====================================================
 //	class Rect
 // =====================================================
