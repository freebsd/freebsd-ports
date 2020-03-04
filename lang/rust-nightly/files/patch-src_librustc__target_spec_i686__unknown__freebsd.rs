--- src/librustc_target/spec/i686_unknown_freebsd.rs.orig	2020-01-17 16:00:01 UTC
+++ src/librustc_target/spec/i686_unknown_freebsd.rs
@@ -2,9 +2,11 @@ use crate::spec::{LinkerFlavor, Target, TargetResult};
 
 pub fn target() -> TargetResult {
     let mut base = super::freebsd_base::opts();
-    base.cpu = "pentium4".to_string();
+    base.cpu = "pentiumpro".to_string();
     base.max_atomic_width = Some(64);
-    base.pre_link_args.get_mut(&LinkerFlavor::Gcc).unwrap().push("-m32".to_string());
+    let pre_link_args = base.pre_link_args.get_mut(&LinkerFlavor::Gcc).unwrap();
+    pre_link_args.push("-m32".to_string());
+    pre_link_args.push("-Wl,-znotext".to_string());
     base.stack_probes = true;
 
     Ok(Target {
