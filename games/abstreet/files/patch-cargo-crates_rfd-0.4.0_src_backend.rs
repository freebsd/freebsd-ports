--- cargo-crates/rfd-0.4.0/src/backend.rs.orig	2021-11-07 16:49:44 UTC
+++ cargo-crates/rfd-0.4.0/src/backend.rs
@@ -3,6 +3,8 @@ use std::future::Future;
 use std::path::PathBuf;
 use std::pin::Pin;
 
+#[cfg(target_os = "freebsd")]
+mod gtk3;
 #[cfg(target_os = "linux")]
 mod gtk3;
 #[cfg(target_os = "macos")]
