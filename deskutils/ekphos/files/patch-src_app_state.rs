--- src/app/state.rs.orig	2026-06-03 11:42:04 UTC
+++ src/app/state.rs
@@ -3499,7 +3499,7 @@ impl App {
 
         #[cfg(target_os = "macos")]
         let _ = Command::new("open").arg(url).spawn();
-        #[cfg(any(target_os = "linux", target_os = "android"))]
+        #[cfg(any(target_os = "freebsd", target_os = "linux", target_os = "android"))]
         let _ = Command::new("xdg-open").arg(url).spawn();
         #[cfg(target_os = "windows")]
         let _ = Command::new("cmd").args(["/c", "start", "", url]).spawn();
@@ -4366,7 +4366,7 @@ impl App {
 
         #[cfg(target_os = "macos")]
         let _ = Command::new("open").arg(&open_path).spawn();
-        #[cfg(any(target_os = "linux", target_os = "android"))]
+        #[cfg(any(target_os = "freebsd", target_os = "linux", target_os = "android"))]
         let _ = Command::new("xdg-open").arg(&open_path).spawn();
         #[cfg(target_os = "windows")]
         let _ = Command::new("cmd").args(["/c", "start", "", &open_path]).spawn();
