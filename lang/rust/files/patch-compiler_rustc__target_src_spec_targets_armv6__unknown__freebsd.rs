--- compiler/rustc_target/src/spec/targets/armv6_unknown_freebsd.rs.orig	2024-10-31 18:07:58.495590000 +0100
+++ compiler/rustc_target/src/spec/targets/armv6_unknown_freebsd.rs	2024-10-31 18:08:05.438220000 +0100
@@ -14,7 +14,6 @@ pub fn target() -> Target {
         arch: "arm".into(),
         options: TargetOptions {
             abi: "eabihf".into(),
-            env: "gnu".into(),
             features: "+v6,+vfp2,-d32".into(),
             max_atomic_width: Some(64),
             mcount: "\u{1}__gnu_mcount_nc".into(),
