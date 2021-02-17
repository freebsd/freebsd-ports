Drop the required version down to 1.0.1 as devel/libgit2 has not been
updated yet

cargo:warning=libgit2/src/transports/ssh.c:11:10: fatal error: 'libssh2.h' file not found
cargo:warning=#include <libssh2.h>

--- cargo-crates/libgit2-sys-0.12.18+1.1.0/build.rs.orig	2021-02-16 15:07:35 UTC
+++ cargo-crates/libgit2-sys-0.12.18+1.1.0/build.rs
@@ -12,7 +12,7 @@ fn main() {
     // To use zlib-ng in zlib-compat mode, we have to build libgit2 ourselves.
     if !zlib_ng_compat {
         let mut cfg = pkg_config::Config::new();
-        if let Ok(lib) = cfg.atleast_version("1.1.0").probe("libgit2") {
+        if let Ok(lib) = cfg.atleast_version("1.0.1").probe("libgit2") {
             for include in &lib.include_paths {
                 println!("cargo:root={}", include.display());
             }
