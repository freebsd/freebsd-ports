--- include/internal/catch_approx.h.orig	2022-10-16 09:02:17 UTC
+++ include/internal/catch_approx.h
@@ -118,8 +118,8 @@ namespace literals {
 } // end namespace Detail
 
 namespace literals {
-    Detail::Approx operator "" _a(long double val);
-    Detail::Approx operator "" _a(unsigned long long val);
+    Detail::Approx operator ""_a(long double val);
+    Detail::Approx operator ""_a(unsigned long long val);
 } // end namespace literals
 
 template<>
