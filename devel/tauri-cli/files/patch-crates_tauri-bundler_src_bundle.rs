-- Use a generic "unknown" bundle type token for platforms without an official
-- Tauri bundle type, allowing the bundler to compile on FreeBSD.
--- crates/tauri-bundler/src/bundle.rs.orig	2026-07-30 17:24:30 UTC
+++ crates/tauri-bundler/src/bundle.rs
@@ -87,7 +87,7 @@ fn patch_binary(binary: &PathBuf, package_type: &Packa
   let bundle_var_index =
     kmp::index_of(BUNDLE_VAR_TOKEN, &file_data).ok_or(crate::Error::MissingBundleTypeVar)?;
   file_data[bundle_var_index..bundle_var_index + BUNDLE_VAR_TOKEN.len()]
-    .copy_from_slice(bundle_type);
+    .copy_from_slice(b"unknown");
 
   std::fs::write(binary, &file_data).map_err(|e| crate::Error::BinaryWriteError(e.to_string()))?;
 
