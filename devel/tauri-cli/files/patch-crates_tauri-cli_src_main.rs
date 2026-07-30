-- Enable the cargo-tauri wrapper binary on FreeBSD.
--- crates/tauri-cli/src/main.rs.orig	2026-07-01 13:31:26 UTC
+++ crates/tauri-cli/src/main.rs
@@ -2,13 +2,13 @@
 // SPDX-License-Identifier: Apache-2.0
 // SPDX-License-Identifier: MIT
 
-#[cfg(not(any(target_os = "macos", target_os = "linux", windows)))]
+#[cfg(not(any(target_os = "macos", target_os = "linux", target_os = "freebsd", windows)))]
 fn main() {
   println!("The Tauri CLI is not supported on this platform");
   std::process::exit(1);
 }
 
-#[cfg(any(target_os = "macos", target_os = "linux", windows))]
+#[cfg(any(target_os = "macos", target_os = "linux", target_os = "freebsd", windows))]
 fn main() {
   use std::env::args_os;
   use std::ffi::OsStr;
