--- simdjson/simdjson.cpp.orig	2026-09-03 05:57:08 UTC
+++ simdjson/simdjson.cpp	2026-09-03 05:57:08 UTC
@@ -112,7 +112,7 @@
 #elif defined(__riscv) && __riscv_xlen == 64
 #define SIMDJSON_IS_RISCV64 1
 #elif defined(__PPC64__) || defined(_M_PPC64)
-#if defined(__ALTIVEC__)
+#if defined(__ALTIVEC__) && defined(__POWER8_VECTOR__)
 #define SIMDJSON_IS_PPC64_VMX 1
 #endif // defined(__ALTIVEC__)
 #else
