https://github.com/rust-lang/git2-rs/commit/a660082a7332

--- cargo-crates/libgit2-sys-0.18.1+1.9.0/build.rs.orig	2006-07-24 01:21:28 UTC
+++ cargo-crates/libgit2-sys-0.18.1+1.9.0/build.rs
@@ -7,7 +7,7 @@ fn try_system_libgit2() -> Result<pkg_config::Library,
 /// Tries to use system libgit2 and emits necessary build script instructions.
 fn try_system_libgit2() -> Result<pkg_config::Library, pkg_config::Error> {
     let mut cfg = pkg_config::Config::new();
-    match cfg.range_version("1.9.0".."1.10.0").probe("libgit2") {
+    match cfg.range_version("1.8.0".."1.10.0").probe("libgit2") {
         Ok(lib) => {
             for include in &lib.include_paths {
                 println!("cargo:root={}", include.display());
