--- src/librustc_back/target/i686_unknown_freebsd.rs.orig	2017-10-09 20:04:51 UTC
+++ src/librustc_back/target/i686_unknown_freebsd.rs
@@ -13,7 +13,7 @@ use target::{Target, TargetResult};
 
 pub fn target() -> TargetResult {
     let mut base = super::freebsd_base::opts();
-    base.cpu = "pentium4".to_string();
+    base.cpu = "pentiumpro".to_string();
     base.max_atomic_width = Some(64);
     base.pre_link_args.get_mut(&LinkerFlavor::Gcc).unwrap().push("-m32".to_string());
     base.stack_probes = true;
