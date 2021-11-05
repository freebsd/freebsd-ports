--- vendor/rustc-ap-rustc_target/src/spec/mod.rs.orig	2021-11-04 11:23:50 UTC
+++ vendor/rustc-ap-rustc_target/src/spec/mod.rs
@@ -805,6 +805,7 @@ supported_targets! {
     ("powerpc-unknown-freebsd", powerpc_unknown_freebsd),
     ("powerpc64-unknown-freebsd", powerpc64_unknown_freebsd),
+    ("riscv64gc-unknown-freebsd", riscv64gc_unknown_freebsd),
     ("x86_64-unknown-freebsd", x86_64_unknown_freebsd),
 
     ("x86_64-unknown-dragonfly", x86_64_unknown_dragonfly),
