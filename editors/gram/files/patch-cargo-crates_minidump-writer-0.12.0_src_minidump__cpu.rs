--- cargo-crates/minidump-writer-0.12.0/src/minidump_cpu.rs.orig	2006-07-24 01:21:28 UTC
+++ cargo-crates/minidump-writer-0.12.0/src/minidump_cpu.rs
@@ -18,6 +18,8 @@ cfg_if::cfg_if! {
         pub(crate) const FP_REG_COUNT: usize = 32;
 
         pub type RawContextCPU = minidump_common::format::CONTEXT_ARM64_OLD;
+    } else if #[cfg(target_arch = "powerpc64")] {
+        pub type RawContextCPU = minidump_common::format::CONTEXT_PPC64;
     } else if #[cfg(target_arch = "mips")] {
         compile_error!("flesh me out");
     } else {
