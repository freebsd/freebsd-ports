-- Build on architectures without SIMD kernels (e.g. powerpc64le).
-- https://github.com/lance-format/lance/pull/9446

--- ../rust/lance-linalg/build.rs.orig	2026-08-30 19:56:29 UTC
+++ ../rust/lance-linalg/build.rs
@@ -19,6 +19,7 @@ fn main() -> Result<(), String> {
     println!(
         "cargo::rustc-check-cfg=cfg(kernel_support, values(\"avx512_f16\", \"avx512_bf16\", \"avx512_dist_table\", \"amx_fp16\"))"
     );
+    println!("cargo::rustc-check-cfg=cfg(simd_fallback)");
 
     println!("cargo:rerun-if-changed=src/simd/f16.c");
     println!("cargo:rerun-if-changed=src/simd/bf16.c");
@@ -31,6 +32,11 @@ fn main() -> Result<(), String> {
     // target_os.
     let target_arch = env::var("CARGO_CFG_TARGET_ARCH").unwrap();
     let target_os = env::var("CARGO_CFG_TARGET_OS").unwrap();
+
+    // Architectures without SIMD kernels back the vector types with plain arrays.
+    if !matches!(target_arch.as_str(), "x86_64" | "aarch64" | "loongarch64") {
+        println!("cargo:rustc-cfg=simd_fallback");
+    }
 
     if target_os == "windows" {
         println!(
