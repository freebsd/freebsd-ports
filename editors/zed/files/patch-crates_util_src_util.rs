--- crates/util/src/util.rs.orig	2026-07-22 23:04:41 UTC
+++ crates/util/src/util.rs
@@ -315,7 +315,7 @@ pub fn get_shell_safe_zed_path(shell_kind: shell::Shel
     use paths::PathExt;
     let mut zed_path =
         std::env::current_exe().context("Failed to determine current zed executable path.")?;
-    if cfg!(target_os = "linux")
+    if cfg!(any(target_os = "linux", target_os = "freebsd"))
         && !zed_path.is_file()
         && let Some(truncated) = zed_path
             .clone()
