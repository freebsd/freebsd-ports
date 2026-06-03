-- Disable zstd BMI2 runtime-dispatch when building for baseline (v1/SSE2).
-- zstd compiles a separate BMI2-optimised Huffman encoder function using
-- BMI2_TARGET_ATTRIBUTE (__attribute__((__target__("lzcnt,bmi,bmi2")))).
-- This produces shrxq and other BMI2 instructions which are part of
-- x86-64-v3, causing the cpu-microarchitecture classifier to report a
-- higher-than-v1 required instruction set. Setting DYNAMIC_BMI2=0 prevents
-- this variant from being compiled entirely.

--- scripts/build/deps/zstd.ts.orig	2026-05-23 01:30:45 UTC
+++ scripts/build/deps/zstd.ts
@@ -65,6 +65,11 @@ export const zstd: Dependency = {
       defines.ZSTD_DISABLE_ASM = 1;
     }
 
+    // Disable BMI2 runtime-dispatch for baseline (v1/SSE2) builds.
+    if (cfg.x64 && cfg.baseline) {
+      defines.DYNAMIC_BMI2 = 0;
+    }
+
     const spec: DirectBuild = {
       kind: "direct",
       sources,
