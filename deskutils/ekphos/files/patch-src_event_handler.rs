--- src/event/handler.rs.orig	2026-06-03 11:42:04 UTC
+++ src/event/handler.rs
@@ -362,7 +362,7 @@ fn handle_mouse_event(app: &mut App, mouse: crossterm:
                             if let Some(open_path) = open_path {
                                 #[cfg(target_os = "macos")]
                                 let _ = std::process::Command::new("open").arg(&open_path).spawn();
-                                #[cfg(any(target_os = "linux", target_os = "android"))]
+                                #[cfg(any(target_os = "freebsd", target_os = "linux", target_os = "android"))]
                                 let _ = std::process::Command::new("xdg-open").arg(&open_path).spawn();
                                 #[cfg(target_os = "windows")]
                                 let _ = std::process::Command::new("cmd").args(["/c", "start", "", &open_path]).spawn();
