-- Use the local NSIS toolset path instead of the system-wide one when copying
-- plugins, avoiding permission errors on systems with a shared NSIS install.
--- crates/tauri-bundler/src/bundle/windows/nsis/mod.rs.orig	2026-07-30 17:17:44 UTC
+++ crates/tauri-bundler/src/bundle/windows/nsis/mod.rs
@@ -244,7 +244,7 @@ fn build_nsis_app_installer(
     let plugins_path = output_path.join("Plugins");
     // copy system plugins (we don't want to modify system installed DLLs, and on some systems there will even be permission errors if we try)
     crate::utils::fs_utils::copy_dir(
-      &system_nsis_toolset_path.join("Plugins").join("x86-unicode"),
+      &nsis_toolset_path.join("Plugins").join("x86-unicode"),
       &plugins_path.join("x86-unicode"),
     )
     .context("failed to copy system NSIS Plugins folder to local copy")?;
