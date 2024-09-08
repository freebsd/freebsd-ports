--- test/common.hpp.orig	2024-07-02 14:50:14 UTC
+++ test/common.hpp
@@ -59,9 +59,18 @@ template <typename T>
 };
 
 template <typename T>
-std::basic_string<T> str_multiply(std::basic_string<T> a, size_t b)
+std::vector<T> str_multiply(std::vector<T> a, size_t b)
 {
-    std::basic_string<T> output;
+    std::vector<T> output;
+    while (b--)
+        output.insert(output.end(), a.begin(), a.end());
+
+    return output;
+}
+
+std::string str_multiply(std::string a, size_t b)
+{
+    std::string output;
     while (b--)
         output += a;
 
