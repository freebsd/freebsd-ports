--- fuzzing/fuzz_lcs_similarity.cpp.orig	2024-07-02 14:50:14 UTC
+++ fuzzing/fuzz_lcs_similarity.cpp
@@ -9,13 +9,13 @@ template <size_t MaxLen>
 #include <string>
 
 template <size_t MaxLen>
-void validate_simd(const std::basic_string<uint8_t>& s1, const std::basic_string<uint8_t>& s2)
+void validate_simd(const std::vector<uint8_t>& s1, const std::vector<uint8_t>& s2)
 {
 #ifdef RAPIDFUZZ_SIMD
     size_t count = s1.size() / MaxLen + ((s1.size() % MaxLen) != 0);
     rapidfuzz::experimental::MultiLCSseq<MaxLen> scorer(count);
 
-    std::vector<std::basic_string<uint8_t>> strings;
+    std::vector<std::vector<uint8_t>> strings;
 
     for (auto it1 = s1.begin(); it1 != s1.end(); it1 += MaxLen) {
         if (std::distance(it1, s1.end()) < static_cast<ptrdiff_t>(MaxLen)) {
@@ -51,7 +51,7 @@ extern "C" int LLVMFuzzerTestOneInput(const uint8_t* d
 
 extern "C" int LLVMFuzzerTestOneInput(const uint8_t* data, size_t size)
 {
-    std::basic_string<uint8_t> s1, s2;
+    std::vector<uint8_t> s1, s2;
     if (!extract_strings(data, size, s1, s2)) {
         return 0;
     }
