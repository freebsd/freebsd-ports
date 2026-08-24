--- karukan-im/fcitx5/build.rs.orig	2026-08-18 02:49:10 UTC
+++ karukan-im/fcitx5/build.rs
@@ -0,0 +1,3 @@
+fn main() {
+    println!("cargo:rustc-link-lib=dylib=omp");
+}
