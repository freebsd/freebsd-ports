--- fuzzing/fuzz_jaro_similarity.cpp.orig	2024-07-02 14:50:14 UTC
+++ fuzzing/fuzz_jaro_similarity.cpp
@@ -14,7 +14,7 @@ template <size_t MaxLen>
 }
 
 template <size_t MaxLen>
-void validate_simd(const std::basic_string<uint8_t>& s1, const std::basic_string<uint8_t>& s2)
+void validate_simd(const std::vector<uint8_t>& s1, const std::vector<uint8_t>& s2)
 {
 #ifdef RAPIDFUZZ_SIMD
     size_t count = s1.size() / MaxLen + ((s1.size() % MaxLen) != 0);
@@ -22,7 +22,7 @@ void validate_simd(const std::basic_string<uint8_t>& s
 
     rapidfuzz::experimental::MultiJaro<MaxLen> scorer(count);
 
-    std::vector<std::basic_string<uint8_t>> strings;
+    std::vector<std::vector<uint8_t>> strings;
 
     for (auto it1 = s1.begin(); it1 != s1.end(); it1 += MaxLen) {
         if (std::distance(it1, s1.end()) < static_cast<ptrdiff_t>(MaxLen)) {
@@ -59,7 +59,7 @@ void validate_simd(const std::basic_string<uint8_t>& s
 #endif
 }
 
-void validate_distance(const std::basic_string<uint8_t>& s1, const std::basic_string<uint8_t>& s2)
+void validate_distance(const std::vector<uint8_t>& s1, const std::vector<uint8_t>& s2)
 {
     double reference_sim = rapidfuzz_reference::jaro_similarity(s1, s2);
     double sim = rapidfuzz::jaro_similarity(s1, s2);
@@ -80,15 +80,15 @@ extern "C" int LLVMFuzzerTestOneInput(const uint8_t* d
 
 extern "C" int LLVMFuzzerTestOneInput(const uint8_t* data, size_t size)
 {
-    std::basic_string<uint8_t> s1, s2;
+    std::vector<uint8_t> s1, s2;
     if (!extract_strings(data, size, s1, s2)) return 0;
 
     validate_distance(s1, s2);
 
     /* test long sequences */
     for (unsigned int i = 2; i < 9; ++i) {
-        std::basic_string<uint8_t> s1_ = str_multiply(s1, pow<size_t>(2, i));
-        std::basic_string<uint8_t> s2_ = str_multiply(s2, pow<size_t>(2, i));
+        std::vector<uint8_t> s1_ = str_multiply(s1, pow<size_t>(2, i));
+        std::vector<uint8_t> s2_ = str_multiply(s2, pow<size_t>(2, i));
 
         if (s1_.size() > 10000 || s2_.size() > 10000) break;
 
