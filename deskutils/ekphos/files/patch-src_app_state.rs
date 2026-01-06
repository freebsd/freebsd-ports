--- src/app/state.rs.orig	2025-12-31 15:47:52 UTC
+++ src/app/state.rs
@@ -1978,7 +1978,7 @@ impl App {
         if let Some(url) = self.current_item_link() {
             #[cfg(target_os = "macos")]
             let _ = Command::new("open").arg(&url).spawn();
-            #[cfg(target_os = "linux")]
+            #[cfg(any(target_os = "linux", target_os = "freebsd"))]
             let _ = Command::new("xdg-open").arg(&url).spawn();
             #[cfg(target_os = "windows")]
             let _ = Command::new("cmd").args(["/c", "start", "", &url]).spawn();
@@ -2406,7 +2406,7 @@ impl App {
             if should_open {
                 #[cfg(target_os = "macos")]
                 let _ = Command::new("open").arg(path).spawn();
-                #[cfg(target_os = "linux")]
+                #[cfg(any(target_os = "linux", target_os = "freebsd"))]
                 let _ = Command::new("xdg-open").arg(path).spawn();
                 #[cfg(target_os = "windows")]
                 let _ = Command::new("cmd").args(["/c", "start", "", path]).spawn();
