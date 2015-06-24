--- src/librustc_back/target/freebsd_base.rs.orig	2015-05-07 14:37:17 UTC
+++ src/librustc_back/target/freebsd_base.rs
@@ -19,9 +19,6 @@ pub fn opts() -> TargetOptions {
         morestack: true,
         has_rpath: true,
         pre_link_args: vec!(
-            "-L/usr/local/lib".to_string(),
-            "-L/usr/local/lib/gcc46".to_string(),
-            "-L/usr/local/lib/gcc44".to_string(),
         ),
 
         .. Default::default()
