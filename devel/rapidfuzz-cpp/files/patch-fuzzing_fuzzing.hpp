--- fuzzing/fuzzing.hpp.orig	2024-07-02 14:50:14 UTC
+++ fuzzing/fuzzing.hpp
@@ -3,8 +3,8 @@
 #include <rapidfuzz/distance/Levenshtein.hpp>
 #include <string>
 
-static inline bool extract_strings(const uint8_t* data, size_t size, std::basic_string<uint8_t>& s1,
-                                   std::basic_string<uint8_t>& s2)
+static inline bool extract_strings(const uint8_t* data, size_t size, std::vector<uint8_t>& s1,
+                                   std::vector<uint8_t>& s2)
 {
     if (size <= sizeof(uint32_t)) {
         return false;
@@ -17,8 +17,8 @@ static inline bool extract_strings(const uint8_t* data
 
     data += sizeof(len1);
     size -= sizeof(len1);
-    s1 = std::basic_string<uint8_t>(data, len1);
-    s2 = std::basic_string<uint8_t>(data + len1, size - len1);
+    s1 = std::vector<uint8_t>(data, len1);
+    s2 = std::vector<uint8_t>(data + len1, size - len1);
     return true;
 }
 
@@ -36,9 +36,9 @@ template <typename T>
 }
 
 template <typename T>
-std::basic_string<T> str_multiply(std::basic_string<T> a, size_t b)
+std::vector<T> str_multiply(std::vector<T> a, size_t b)
 {
-    std::basic_string<T> output;
+    std::vector<T> output;
     while (b--)
         output += a;
 
@@ -46,7 +46,7 @@ template <typename T>
 }
 
 template <typename T>
-void print_seq(const std::string& name, const std::basic_string<T>& seq)
+void print_seq(const std::string& name, const std::vector<T>& seq)
 {
     std::cout << name << " len: " << seq.size() << " content: ";
     for (const auto& ch : seq)
