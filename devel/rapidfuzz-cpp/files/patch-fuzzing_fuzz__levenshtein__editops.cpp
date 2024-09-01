--- fuzzing/fuzz_levenshtein_editops.cpp.orig	2024-07-02 14:50:14 UTC
+++ fuzzing/fuzz_levenshtein_editops.cpp
@@ -7,7 +7,7 @@
 #include <stdexcept>
 #include <string>
 
-void validate_editops(const std::basic_string<uint8_t>& s1, const std::basic_string<uint8_t>& s2,
+void validate_editops(const std::vector<uint8_t>& s1, const std::vector<uint8_t>& s2,
                       size_t score, size_t score_hint = std::numeric_limits<size_t>::max())
 {
     rapidfuzz::Editops ops = rapidfuzz::levenshtein_editops(s1, s2, score_hint);
@@ -17,7 +17,7 @@ extern "C" int LLVMFuzzerTestOneInput(const uint8_t* d
 
 extern "C" int LLVMFuzzerTestOneInput(const uint8_t* data, size_t size)
 {
-    std::basic_string<uint8_t> s1, s2;
+    std::vector<uint8_t> s1, s2;
     if (!extract_strings(data, size, s1, s2)) return 0;
 
     /* hirschbergs algorithm is only used for very long sequences which are apparently not generated a lot by
