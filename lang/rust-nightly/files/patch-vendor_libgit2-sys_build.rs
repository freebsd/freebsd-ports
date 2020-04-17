--- vendor/libgit2-sys/build.rs.orig	2020-04-17 09:21:48 UTC
+++ vendor/libgit2-sys/build.rs
@@ -8,7 +8,7 @@ fn main() {
     let ssh = env::var("CARGO_FEATURE_SSH").is_ok();
 
     let mut cfg = pkg_config::Config::new();
-    if let Ok(lib) = cfg.atleast_version("1.0.0").probe("libgit2") {
+    if let Ok(lib) = cfg.atleast_version("0.99.0").probe("libgit2") {
         for include in &lib.include_paths {
             println!("cargo:root={}", include.display());
         }
