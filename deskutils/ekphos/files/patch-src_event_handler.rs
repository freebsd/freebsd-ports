--- src/event/handler.rs.orig	2025-12-31 15:47:52 UTC
+++ src/event/handler.rs
@@ -226,7 +226,7 @@ fn handle_mouse_event(app: &mut App, mouse: crossterm:
                         if let Some(url) = app.find_clicked_link(idx, mouse_x, app.content_area.x) {
                             #[cfg(target_os = "macos")]
                             let _ = std::process::Command::new("open").arg(&url).spawn();
-                            #[cfg(target_os = "linux")]
+                            #[cfg(any(target_os = "linux", target_os = "freebsd"))]
                             let _ = std::process::Command::new("xdg-open").arg(&url).spawn();
                             #[cfg(target_os = "windows")]
                             let _ = std::process::Command::new("cmd").args(["/c", "start", "", &url]).spawn();
@@ -245,7 +245,7 @@ fn handle_mouse_event(app: &mut App, mouse: crossterm:
                             if should_open {
                                 #[cfg(target_os = "macos")]
                                 let _ = std::process::Command::new("open").arg(path).spawn();
-                                #[cfg(target_os = "linux")]
+                                #[cfg(any(target_os = "linux", target_os = "freebsd"))]
                                 let _ = std::process::Command::new("xdg-open").arg(path).spawn();
                                 #[cfg(target_os = "windows")]
                                 let _ = std::process::Command::new("cmd").args(["/c", "start", "", path]).spawn();
@@ -1609,7 +1609,7 @@ fn handle_normal_mode(app: &mut App, key: crossterm::e
                         crate::app::LinkInfo::Markdown { url, .. } => {
                             #[cfg(target_os = "macos")]
                             let _ = std::process::Command::new("open").arg(&url).spawn();
-                            #[cfg(target_os = "linux")]
+                            #[cfg(any(target_os = "linux", target_os = "freebsd"))]
                             let _ = std::process::Command::new("xdg-open").arg(&url).spawn();
                             #[cfg(target_os = "windows")]
                             let _ = std::process::Command::new("cmd").args(["/c", "start", "", &url]).spawn();
