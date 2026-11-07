--- unittest/test_hashutil.cpp.orig	2026-10-18 11:12:58 UTC
+++ unittest/test_hashutil.cpp
@@ -381,8 +381,32 @@ TEST_CASE("check_for_source_code_patterns: macro-expan
   CHECK(result.contains(SourceCodeScan::found_embed));
 }
 
+TEST_CASE("check_for_source_code_patterns: macro-expanded incbin operand")
+{
+  TestContext test_context;
+
+  const std::string source = FMT(".inc{}bin RESOURCE\n", "");
+  SourceCodeScanResult result;
+
+  SUBCASE("scalar")
+  {
+    result = check_for_source_code_patterns_scalar(source);
+  }
+
 #ifdef HAVE_AVX2
+  if (util::cpu_supports_avx2()) {
+    SUBCASE("avx2")
+    {
+      result = check_for_source_code_patterns_avx2(source);
+    }
+  }
+#endif
 
+  CHECK(result.contains(SourceCodeScan::found_incbin));
+}
+
+#ifdef HAVE_AVX2
+
 static bool
 contains_embed_directive(std::string_view source)
 {
@@ -532,7 +556,7 @@ TEST_CASE("check_for_source_code_patterns_avx2: no inc
           * doctest::skip(!util::cpu_supports_avx2()))
 {
   CHECK_FALSE(contains_incbin_directive(
-    FMT("\n    #include <stdio.h>\n    .inc{}bin data.bin\n  ", "")));
+    FMT("\n    #include <stdio.h>\n    .inc{}bin(data)\n  ", "")));
 }
 
 TEST_CASE("check_for_source_code_patterns_avx2: simple incbin"
