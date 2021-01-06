--- compiler/rustc_target/src/spec/powerpc64_unknown_freebsd.rs.orig	2020-12-29 04:03:08 UTC
+++ compiler/rustc_target/src/spec/powerpc64_unknown_freebsd.rs
@@ -11,6 +11,10 @@ pub fn target() -> Target {
         pointer_width: 64,
         data_layout: "E-m:e-i64:64-n32:64".to_string(),
         arch: "powerpc64".to_string(),
-        options: TargetOptions { endian: "big".to_string(), mcount: "_mcount".to_string(), ..base },
+        options: TargetOptions {
+            endian: "big".to_string(),
+            mcount: "_mcount".to_string(),
+            llvm_abiname: "elfv2".to_string(),
+            ..base },
     }
 }
