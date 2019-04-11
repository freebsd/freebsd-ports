--- src/librustc_target/spec/i686_unknown_freebsd.rs.orig	2019-04-08 12:42:31 UTC
+++ src/librustc_target/spec/i686_unknown_freebsd.rs
@@ -2,7 +2,7 @@ use crate::spec::{LinkerFlavor, Target, TargetResult};
 
 pub fn target() -> TargetResult {
     let mut base = super::freebsd_base::opts();
-    base.cpu = "pentium4".to_string();
+    base.cpu = "pentiumpro".to_string();
     base.max_atomic_width = Some(64);
     base.pre_link_args.get_mut(&LinkerFlavor::Gcc).unwrap().push("-m32".to_string());
     base.stack_probes = true;
