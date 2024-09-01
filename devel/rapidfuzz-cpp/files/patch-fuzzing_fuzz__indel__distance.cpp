--- fuzzing/fuzz_indel_distance.cpp.orig	2024-07-02 14:50:14 UTC
+++ fuzzing/fuzz_indel_distance.cpp
@@ -8,7 +8,7 @@
 #include <stdexcept>
 #include <string>
 
-void validate_distance(const std::basic_string<uint8_t>& s1, const std::basic_string<uint8_t>& s2,
+void validate_distance(const std::vector<uint8_t>& s1, const std::vector<uint8_t>& s2,
                        size_t score_cutoff)
 {
     auto dist = rapidfuzz::indel_distance(s1, s2, score_cutoff);
@@ -25,7 +25,7 @@ extern "C" int LLVMFuzzerTestOneInput(const uint8_t* d
 
 extern "C" int LLVMFuzzerTestOneInput(const uint8_t* data, size_t size)
 {
-    std::basic_string<uint8_t> s1, s2;
+    std::vector<uint8_t> s1, s2;
     if (!extract_strings(data, size, s1, s2)) return 0;
 
     validate_distance(s1, s2, 0);
