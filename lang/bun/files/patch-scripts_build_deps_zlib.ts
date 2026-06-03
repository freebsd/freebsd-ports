-- Skip AVX2/AVX-512 zlib-ng kernels when building for baseline (v1/SSE2).
-- zlib-ng unconditionally compiles X86_AVX2, X86_AVX512, X86_AVX512VNNI and
-- X86_VPCLMULQDQ_CRC kernels with explicit -mavx512* flags for all x86-64
-- builds. In baseline mode the binary must contain only SSE2-level code so that
-- it runs on any x86-64 CPU. These kernels are runtime-dispatched correctly but
-- the static AVX-512 instructions still appear in the ELF binary and fail the
-- cpu-microarchitecture classifier test.

--- scripts/build/deps/zlib.ts.orig	2026-05-23 01:30:45 UTC
+++ scripts/build/deps/zlib.ts
@@ -208,6 +208,10 @@ export const zlib: Dependency = {
     }
 
     for (const k of kernels) {
+      // Skip AVX2/AVX-512 kernels for baseline (v1/SSE2) builds.
+      if (cfg.x64 && cfg.baseline && (k.define === "X86_AVX2" ||
+          k.define === "X86_AVX512" || k.define === "X86_AVX512VNNI" ||
+          k.define === "X86_VPCLMULQDQ_CRC")) continue;
       defines[k.define] = true;
       for (const s of k.sources) {
         sources.push({ path: `arch/${archDir}/${s}.c`, cflags: [...k.flags, "-fno-lto"] });
