-- Exclude all x86-64 ELF assembly from BoringSSL when building for baseline
-- (v1/SSE2). BoringSSL ships assembly that uses AVX, AVX2, AVX-512, BMI2, and
-- ADX instructions. In baseline mode the binary must contain only SSE2-level
-- code so that it runs on any x86-64 CPU. Setting OPENSSL_NO_ASM causes all
-- BoringSSL C dispatch code to use pure-C fallbacks; filtering the assembly
-- from the source list ensures none of the higher-ISA objects are linked in.
-- The AVX-512 bun-internal patch is kept as belt-and-suspenders.

--- scripts/build/deps/boringssl.ts.orig	2026-05-23 02:36:52 UTC
+++ scripts/build/deps/boringssl.ts
@@ -36,10 +36,26 @@ export const boringssl: Dependency = {
     commit: BORINGSSL_COMMIT,
   }),
 
+  // Apply source patches for baseline (v1/SSE2) builds to guard the AVX-512
+  // GCM declarations and dispatch paths with OPENSSL_NO_AVX512, matching the
+  // exclusion of the AVX-512 assembly file below.
+  patches: cfg =>
+    cfg.x64 && cfg.baseline
+      ? ["patches/boringssl/disable-avx512-gcm.patch"]
+      : [],
+
   build: cfg => {
     // win-x64 uses NASM-syntax .asm; everything else (including win-aarch64)
     // uses gas .S that clang assembles.
-    const asm = cfg.windows && cfg.x64 ? NASM : ASM;
+    let asm = cfg.windows && cfg.x64 ? NASM : ASM;
+    // For baseline (v1/SSE2) builds: exclude ALL ELF x86-64 assembly.
+    // OPENSSL_NO_ASM (set below) causes C fallbacks to be used for all crypto.
+    // The wrong-arch files already assemble to empty TUs; the x86-64 linux
+    // ones (including AVX2, BMI2, ADX, SSSE3) must also be removed so their
+    // instructions do not appear in the final binary.
+    if (cfg.x64 && cfg.baseline) {
+      asm = asm.filter(f => !f.endsWith("-linux.S") && !f.includes("fiat_"));
+    }
 
     const spec: DirectBuild = {
       kind: "direct",
@@ -53,6 +69,11 @@ export const boringssl: Dependency = {
           WIN32_LEAN_AND_MEAN: true,
           NOMINMAX: true,
           _CRT_SECURE_NO_WARNINGS: true,
+        }),
+        // Disable ASM dispatch and guard AVX-512 GCM C code for baseline builds.
+        ...(cfg.x64 && cfg.baseline && {
+          OPENSSL_NO_ASM: true,
+          OPENSSL_NO_AVX512: true,
         }),
       },
       cflags: cfg.windows
