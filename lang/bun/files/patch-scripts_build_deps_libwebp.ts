-- Exclude AVX2 DSP sources from libwebp for baseline (v1/SSE2) builds.
-- libwebp compiles lossless_avx2.c and lossless_enc_avx2.c with -mavx2 so the
-- compiler emits AVX2 instructions. Although libwebp uses runtime CPU dispatch
-- so these paths are only executed when AVX2 is detected, the instructions are
-- present in the ELF binary and cause the cpu-microarchitecture classifier to
-- require AVX2. Exclude the _avx2.c files entirely for baseline builds; the
-- SSE2 code paths remain available and are selected at runtime.

--- scripts/build/deps/libwebp.ts.orig	2026-05-23 02:36:10 UTC
+++ scripts/build/deps/libwebp.ts
@@ -98,14 +98,20 @@ const SHARPYUV = [
 // (on arm64 these compile to the stub body and the x86 -m flags are invalid).
 // Runtime CPU dispatch in dsp/cpu.c picks the best available, so a baseline
 // binary still runs on pre-AVX2 hardware.
-function simd(path: string, x64: boolean) {
+function simd(path: string, x64: boolean, baseline: boolean = false) {
   if (x64) {
     for (const [suf, flag] of [
       ["_avx2.c", "-mavx2"],
       ["_sse41.c", "-msse4.1"],
       ["_sse2.c", "-msse2"],
     ] as const) {
-      if (path.endsWith(suf)) return { path, cflags: [flag] };
+      if (path.endsWith(suf)) {
+        // Exclude AVX2 files for baseline (v1/SSE2) builds: even though
+        // libwebp uses runtime CPU dispatch, the AVX2 instructions must not
+        // be present in the ELF binary at all for baseline compliance.
+        if (baseline && suf === "_avx2.c") return null;
+        return { path, cflags: [flag] };
+      }
     }
   }
   return path;
@@ -126,11 +132,11 @@ export const libwebp: Dependency = {
     sources: [
       ...DEC.map(f => `src/dec/${f}.c`),
       ...ENC.map(f => `src/enc/${f}.c`),
-      ...DSP.map(f => simd(`src/dsp/${f}.c`, cfg.x64)),
+      ...DSP.map(f => simd(`src/dsp/${f}.c`, cfg.x64, cfg.baseline)).filter(Boolean),
       ...UTILS.map(f => `src/utils/${f}.c`),
       ...DEMUX.map(f => `src/demux/${f}.c`),
       ...MUX.map(f => `src/mux/${f}.c`),
-      ...SHARPYUV.map(f => simd(`sharpyuv/${f}.c`, cfg.x64)),
+      ...SHARPYUV.map(f => simd(`sharpyuv/${f}.c`, cfg.x64, cfg.baseline)).filter(Boolean),
     ],
     // src/webp/*.h is the public API; internal headers use "src/..."
     // includes from the repo root, sharpyuv uses "sharpyuv/...".
