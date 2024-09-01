--- fuzzing/fuzz_indel_editops.cpp.orig	2024-07-02 14:50:14 UTC
+++ fuzzing/fuzz_indel_editops.cpp
@@ -9,7 +9,7 @@ extern "C" int LLVMFuzzerTestOneInput(const uint8_t* d
 
 extern "C" int LLVMFuzzerTestOneInput(const uint8_t* data, size_t size)
 {
-    std::basic_string<uint8_t> s1, s2;
+    std::vector<uint8_t> s1, s2;
     if (!extract_strings(data, size, s1, s2)) return 0;
 
     size_t score = rapidfuzz_reference::indel_distance(s1, s2);
