--- compiler/rustc_llvm/build.rs.orig	2021-11-29 19:27:11 UTC
+++ compiler/rustc_llvm/build.rs
@@ -276,8 +276,11 @@ fn main() {
         "stdc++"
     };
 
-    // RISC-V requires libatomic for sub-word atomic operations
-    if target.starts_with("riscv") {
+    // RISC-V GCC erroneously requires libatomic for sub-word
+    // atomic operations. FreeBSD uses Clang as its system
+    // compiler and provides no libatomic in its base system so
+    // does not want this.
+    if !target.contains("freebsd") && target.starts_with("riscv") {
         println!("cargo:rustc-link-lib=atomic");
     }
 
