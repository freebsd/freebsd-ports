--- compiler/rustc_target/src/spec/targets/armv7_unknown_freebsd.rs.orig	2024-10-31 18:07:51.199947000 +0100
+++ compiler/rustc_target/src/spec/targets/armv7_unknown_freebsd.rs	2024-10-31 18:08:14.463398000 +0100
@@ -14,7 +14,6 @@ pub fn target() -> Target {
         arch: "arm".into(),
         options: TargetOptions {
             abi: "eabihf".into(),
-            env: "gnu".into(),
             features: "+v7,+vfp3,-d32,+thumb2,-neon".into(),
             max_atomic_width: Some(64),
             mcount: "\u{1}__gnu_mcount_nc".into(),
