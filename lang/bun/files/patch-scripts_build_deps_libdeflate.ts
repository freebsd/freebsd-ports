-- Disable AVX2/AVX-512 SIMD implementations in libdeflate for baseline builds.
-- libdeflate uses _target_attribute("avx2") / _target_attribute("pclmul,avx")
-- to compile runtime-dispatched SIMD variants regardless of -march. In baseline
-- (v1/SSE2) mode these still produce AVX2/AVX instructions in the ELF binary,
-- causing the cpu-microarchitecture classifier to report a level above SSE2.
-- Two mechanisms are used:
--   1. LIBDEFLATE_DISABLE_SIMD_ABOVE_SSE2 / LIBDEFLATE_ASSEMBLER_DOES_NOT_
--      SUPPORT_AVX512VNNI / _VPCLMULQDQ: preprocessor defines that gate the
--      AVX2/AVX-512 code paths in the headers.
--   2. bun-internal patches (bun-libdeflate-adler32-disable-avx2.patch and
--      bun-libdeflate-crc32-disable-avx.patch, installed by the Makefile
--      post-patch target) are applied by bun's fetchDep when it extracts the
--      libdeflate tarball from cache.

--- scripts/build/deps/libdeflate.ts.orig	2026-05-12 22:12:49 UTC
+++ scripts/build/deps/libdeflate.ts
@@ -21,7 +21,18 @@ export const libdeflate: Dependency = {
     commit: LIBDEFLATE_COMMIT,
   }),
 
-  build: () => ({
+  // Apply SIMD-disable patches for baseline (v1/SSE2) builds so that
+  // _target_attribute("avx2") and _target_attribute("pclmul,avx") functions
+  // are excluded from the extracted source before compilation.
+  patches: cfg =>
+    cfg.x64 && cfg.baseline
+      ? [
+          "patches/libdeflate/adler32-disable-avx2.patch",
+          "patches/libdeflate/crc32-disable-avx.patch",
+        ]
+      : [],
+
+  build: cfg => ({
     kind: "direct",
     sources: [
       "lib/utils.c",
@@ -39,6 +50,12 @@ export const libdeflate: Dependency = {
     // libdeflate.h + common_defs.h live at the repo root; sources reach
     // lib/*.h by relative include from their own directory.
     includes: ["."],
+    // Disable AVX2/AVX-512 SIMD implementations for baseline (v1/SSE2) builds.
+    defines: cfg.x64 && cfg.baseline ? {
+      LIBDEFLATE_DISABLE_SIMD_ABOVE_SSE2: true,
+      LIBDEFLATE_ASSEMBLER_DOES_NOT_SUPPORT_AVX512VNNI: true,
+      LIBDEFLATE_ASSEMBLER_DOES_NOT_SUPPORT_VPCLMULQDQ: true,
+    } : {},
   }),
 
   provides: () => ({
