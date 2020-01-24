--- src/librustc_target/spec/i686_unknown_freebsd.rs.orig	2020-01-23 19:40:44 UTC
+++ src/librustc_target/spec/i686_unknown_freebsd.rs
@@ -2,7 +2,7 @@ use crate::spec::{LinkerFlavor, Target, TargetResult};
 
 pub fn target() -> TargetResult {
     let mut base = super::freebsd_base::opts();
-    base.cpu = "pentium4".to_string();
+    base.cpu = "pentiumpro".to_string();
     base.max_atomic_width = Some(64);
     let pre_link_args = base.pre_link_args.get_mut(&LinkerFlavor::Gcc).unwrap();
     pre_link_args.push("-m32".to_string());
