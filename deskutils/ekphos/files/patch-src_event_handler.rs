--- src/event/handler.rs.orig	2026-01-06 22:24:18 UTC
+++ src/event/handler.rs
@@ -236,7 +236,7 @@ fn handle_mouse_event(app: &mut App, mouse: crossterm:
                         else if let Some(url) = app.find_clicked_link(idx, mouse_x, app.content_area.x) {
                             #[cfg(target_os = "macos")]
                             let _ = std::process::Command::new("open").arg(&url).spawn();
-                            #[cfg(target_os = "linux")]
+                            #[cfg(any(target_os = "linux", target_os = "freebsd"))]
                             let _ = std::process::Command::new("xdg-open").arg(&url).spawn();
                             #[cfg(target_os = "windows")]
                             let _ = std::process::Command::new("cmd").args(["/c", "start", "", &url]).spawn();
@@ -259,7 +259,7 @@ fn handle_mouse_event(app: &mut App, mouse: crossterm:
                             if let Some(open_path) = open_path {
                                 #[cfg(target_os = "macos")]
                                 let _ = std::process::Command::new("open").arg(&open_path).spawn();
-                                #[cfg(target_os = "linux")]
+                                #[cfg(any(target_os = "linux", target_os = "freebsd"))]
                                 let _ = std::process::Command::new("xdg-open").arg(&open_path).spawn();
                                 #[cfg(target_os = "windows")]
                                 let _ = std::process::Command::new("cmd").args(["/c", "start", "", &open_path]).spawn();
