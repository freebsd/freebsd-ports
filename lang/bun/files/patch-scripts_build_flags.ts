-- Support explicit CPU target in C++ compiler flags.
-- If 'cpu' is defined in the configuration, use -march=${cpu} to target
-- the specified microarchitecture, overriding the default baseline/haswell logic.
--
-- Change x64 baseline from nehalem to x86-64-v1 to ensure maximum compatibility
-- on older hardware.
--
-- Add HWY_COMPILE_ONLY_STATIC define for baseline x64 builds. Google Highway's
-- foreach_target.h normally recompiles each translation unit for every supported
-- ISA target via #pragma clang attribute push(__attribute__((target(...)))),
-- ignoring the -march flag. HWY_COMPILE_ONLY_STATIC restricts this to the static
-- target determined by -march (SSE2 with -march=x86-64), preventing AVX/AVX-512
-- code from appearing in the binary when CPUTYPE is unset.

--- scripts/build/flags.ts.orig	2026-05-12 22:12:49 UTC
+++ scripts/build/flags.ts
@@ -624,6 +624,11 @@ export const defines: Flag[] = [
 
   // ─── Config-dependent ───
   {
+    flag: "HWY_COMPILE_ONLY_STATIC",
+    when: c => c.x64 && c.cpu === undefined && c.baseline,
+    desc: "x64 baseline: compile Highway for SSE2 only (matches -march=x86-64)",
+  },
+  {
     flag: "ASSERT_ENABLED=1",
     when: c => c.assertions,
     desc: "Enable runtime assertions",
