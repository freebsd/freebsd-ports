--- src/app/state.rs.orig	2026-01-06 22:24:18 UTC
+++ src/app/state.rs
@@ -2647,7 +2647,7 @@ impl App {
         if let Some(url) = self.current_item_link() {
             #[cfg(target_os = "macos")]
             let _ = Command::new("open").arg(&url).spawn();
-            #[cfg(target_os = "linux")]
+            #[cfg(any(target_os = "linux", target_os = "freebsd"))]
             let _ = Command::new("xdg-open").arg(&url).spawn();
             #[cfg(target_os = "windows")]
             let _ = Command::new("cmd").args(["/c", "start", "", &url]).spawn();
@@ -3469,7 +3469,7 @@ impl App {
 
         #[cfg(target_os = "macos")]
         let _ = Command::new("open").arg(&open_path).spawn();
-        #[cfg(target_os = "linux")]
+        #[cfg(any(target_os = "linux", target_os = "freebsd"))]
         let _ = Command::new("xdg-open").arg(&open_path).spawn();
         #[cfg(target_os = "windows")]
         let _ = Command::new("cmd").args(["/c", "start", "", &open_path]).spawn();
