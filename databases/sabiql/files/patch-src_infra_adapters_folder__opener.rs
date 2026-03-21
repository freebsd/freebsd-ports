--- src/infra/adapters/folder_opener.rs.orig	2026-03-17 13:16:27 UTC
+++ src/infra/adapters/folder_opener.rs
@@ -8,11 +8,11 @@ impl FolderOpener for NativeFolderOpener {
     fn open(&self, path: &Path) -> Result<(), String> {
         #[cfg(target_os = "macos")]
         let result = std::process::Command::new("open").arg(path).spawn();
-        #[cfg(target_os = "linux")]
+        #[cfg(any(target_os = "freebsd", target_os = "linux"))]
         let result = std::process::Command::new("xdg-open").arg(path).spawn();
         #[cfg(target_os = "windows")]
         let result = std::process::Command::new("explorer").arg(path).spawn();
-        #[cfg(not(any(target_os = "macos", target_os = "linux", target_os = "windows")))]
+        #[cfg(not(any(target_os = "freebsd", target_os = "macos", target_os = "linux", target_os = "windows")))]
         compile_error!("FolderOpener: unsupported target OS");
 
         result.map(|_| ()).map_err(|e| e.to_string())
