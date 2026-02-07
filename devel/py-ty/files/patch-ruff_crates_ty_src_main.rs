--- ruff/crates/ty/src/main.rs.orig	2025-12-31 06:44:52 UTC
+++ ruff/crates/ty/src/main.rs
@@ -6,6 +6,7 @@ use ty::{ExitStatus, run};
     not(target_os = "macos"),
     not(target_os = "windows"),
     not(target_os = "openbsd"),
+    not(target_os = "freebsd"),
     not(target_os = "aix"),
     not(target_os = "android"),
     any(
