--- bench/bench-lcs.cpp.orig	2024-07-02 14:50:14 UTC
+++ bench/bench-lcs.cpp
@@ -20,9 +20,9 @@ template <typename T>
 }
 
 template <typename T>
-std::basic_string<T> str_multiply(std::basic_string<T> a, unsigned int b)
+std::vector<T> str_multiply(std::vector<T> a, unsigned int b)
 {
-    std::basic_string<T> output;
+    std::vector<T> output;
     while (b--)
         output += a;
 
