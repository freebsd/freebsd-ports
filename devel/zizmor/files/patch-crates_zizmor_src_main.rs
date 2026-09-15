--- crates/zizmor/src/main.rs.orig	2026-09-14 06:39:01 UTC
+++ crates/zizmor/src/main.rs
@@ -51,6 +51,7 @@ mod utils;
 #[cfg(all(
     not(target_family = "windows"),
     not(target_os = "openbsd"),
+    not(target_os = "freebsd"),
     any(
         target_arch = "x86_64",
         target_arch = "aarch64",
