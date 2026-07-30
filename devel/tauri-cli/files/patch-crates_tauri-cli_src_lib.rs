-- Enable the tauri-cli library crate on FreeBSD.
--- crates/tauri-cli/src/lib.rs.orig	2026-07-01 13:31:26 UTC
+++ crates/tauri-cli/src/lib.rs
@@ -8,7 +8,7 @@
   html_logo_url = "https://github.com/tauri-apps/tauri/raw/dev/.github/icon.png",
   html_favicon_url = "https://github.com/tauri-apps/tauri/raw/dev/.github/icon.png"
 )]
-#![cfg(any(target_os = "macos", target_os = "linux", windows))]
+#![cfg(any(target_os = "macos", target_os = "linux", target_os = "freebsd", windows))]
 
 mod acl;
 mod add;
