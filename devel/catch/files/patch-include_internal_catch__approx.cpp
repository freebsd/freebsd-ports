--- include/internal/catch_approx.cpp.orig	2022-10-16 09:02:17 UTC
+++ include/internal/catch_approx.cpp
@@ -73,10 +73,10 @@ namespace literals {
 } // end namespace Detail
 
 namespace literals {
-    Detail::Approx operator "" _a(long double val) {
+    Detail::Approx operator ""_a(long double val) {
         return Detail::Approx(val);
     }
-    Detail::Approx operator "" _a(unsigned long long val) {
+    Detail::Approx operator ""_a(unsigned long long val) {
         return Detail::Approx(val);
     }
 } // end namespace literals
