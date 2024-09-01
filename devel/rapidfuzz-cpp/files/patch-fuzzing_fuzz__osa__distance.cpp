--- fuzzing/fuzz_osa_distance.cpp.orig	2024-07-02 14:50:14 UTC
+++ fuzzing/fuzz_osa_distance.cpp
@@ -8,8 +8,8 @@
 #include <stdexcept>
 #include <string>
 
-void validate_distance(size_t reference_dist, const std::basic_string<uint8_t>& s1,
-                       const std::basic_string<uint8_t>& s2, size_t score_cutoff)
+void validate_distance(size_t reference_dist, const std::vector<uint8_t>& s1,
+                       const std::vector<uint8_t>& s2, size_t score_cutoff)
 {
     if (reference_dist > score_cutoff) reference_dist = score_cutoff + 1;
 
@@ -26,7 +26,7 @@ extern "C" int LLVMFuzzerTestOneInput(const uint8_t* d
 
 extern "C" int LLVMFuzzerTestOneInput(const uint8_t* data, size_t size)
 {
-    std::basic_string<uint8_t> s1, s2;
+    std::vector<uint8_t> s1, s2;
     if (!extract_strings(data, size, s1, s2)) return 0;
 
     size_t reference_dist = rapidfuzz_reference::osa_distance(s1, s2);
@@ -40,8 +40,8 @@ extern "C" int LLVMFuzzerTestOneInput(const uint8_t* d
 
     /* test long sequences */
     for (unsigned int i = 2; i < 9; ++i) {
-        std::basic_string<uint8_t> s1_ = str_multiply(s1, pow<size_t>(2, i));
-        std::basic_string<uint8_t> s2_ = str_multiply(s2, pow<size_t>(2, i));
+        std::vector<uint8_t> s1_ = str_multiply(s1, pow<size_t>(2, i));
+        std::vector<uint8_t> s2_ = str_multiply(s2, pow<size_t>(2, i));
 
         if (s1_.size() > 10000 || s2_.size() > 10000) break;
 
