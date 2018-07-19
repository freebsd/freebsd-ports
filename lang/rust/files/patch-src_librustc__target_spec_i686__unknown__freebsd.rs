--- src/librustc_target/spec/i686_unknown_freebsd.rs.orig	2018-06-19 04:35:53 UTC
+++ src/librustc_target/spec/i686_unknown_freebsd.rs
@@ -12,7 +12,7 @@ use spec::{LinkerFlavor, Target, TargetResult};
 
 pub fn target() -> TargetResult {
     let mut base = super::freebsd_base::opts();
-    base.cpu = "pentium4".to_string();
+    base.cpu = "pentiumpro".to_string();
     base.max_atomic_width = Some(64);
     base.pre_link_args.get_mut(&LinkerFlavor::Gcc).unwrap().push("-m32".to_string());
     base.stack_probes = true;
