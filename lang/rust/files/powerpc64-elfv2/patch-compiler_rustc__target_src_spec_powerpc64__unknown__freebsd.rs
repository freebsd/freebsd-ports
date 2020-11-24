--- compiler/rustc_target/src/spec/powerpc64_unknown_freebsd.rs.orig	2020-07-15 11:31:58 UTC
+++ compiler/rustc_target/src/spec/powerpc64_unknown_freebsd.rs
@@ -17,6 +17,10 @@ pub fn target() -> TargetResult {
         target_env: String::new(),
         target_vendor: "unknown".to_string(),
         linker_flavor: LinkerFlavor::Gcc,
-        options: TargetOptions { target_mcount: "_mcount".to_string(), ..base },
+        options: TargetOptions {
+            target_mcount: "_mcount".to_string(),
+            llvm_abiname: "elfv2".to_string(),
+            ..base
+        },
     })
 }
