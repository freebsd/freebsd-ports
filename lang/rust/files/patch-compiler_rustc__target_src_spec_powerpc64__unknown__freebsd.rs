--- compiler/rustc_target/src/spec/powerpc64_unknown_freebsd.rs.orig	2020-12-29 04:03:08 UTC
+++ compiler/rustc_target/src/spec/powerpc64_unknown_freebsd.rs
@@ -12,6 +12,10 @@ pub fn target() -> Target {
         pointer_width: 64,
         data_layout: "E-m:e-i64:64-n32:64".into(),
         arch: "powerpc64".into(),
-        options: TargetOptions { endian: Endian::Big, mcount: "_mcount".into(), ..base },
+        options: TargetOptions {
+            endian: Endian::Big,
+            mcount: "_mcount".into(),
+            llvm_abiname: "elfv2".into(),
+            ..base },
     }
 }
