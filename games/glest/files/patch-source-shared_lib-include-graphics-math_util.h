--- ./source/shared_lib/include/graphics/math_util.h.bak	2014-08-10 15:21:32.000000000 -0400
+++ ./source/shared_lib/include/graphics/math_util.h	2014-08-10 15:23:08.000000000 -0400
@@ -23,6 +23,16 @@
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
