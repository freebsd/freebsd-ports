-- Support explicit CPU target in Zig build.
-- If 'cpu' is defined in the configuration, pass it as the target CPU to Zig,
-- overriding the default baseline/haswell logic on x86_64.

--- scripts/build/zig.ts.orig	2026-05-12 22:12:49 UTC
+++ scripts/build/zig.ts
@@ -188,16 +188,17 @@ export function zigOptimize(cfg: Config): "Debug" | "R
  *
  * arm64: apple_m1 (darwin), cortex_a76 (windows — no ARMv9 windows yet),
  *   native (linux — no baseline arm64 builds needed).
- * x64: nehalem (baseline, pre-AVX), haswell (AVX2).
+ * x64: x86_64 (baseline, SSE2), haswell (AVX2).
  */
 export function zigCpu(cfg: Config): string {
+  if (cfg.cpu !== undefined) return cfg.cpu;
   if (cfg.arm64) {
     if (cfg.darwin) return "apple_m1";
     if (cfg.windows) return "cortex_a76";
     return "native";
   }
   // x64
-  return cfg.baseline ? "nehalem" : "haswell";
+  return cfg.baseline ? "x86_64" : "haswell";
 }
 
 /**
