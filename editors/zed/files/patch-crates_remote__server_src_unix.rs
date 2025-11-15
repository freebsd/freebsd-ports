--- crates/remote_server/src/unix.rs.orig	2025-11-15 05:26:18 UTC
+++ crates/remote_server/src/unix.rs
@@ -347,6 +347,7 @@ pub fn execute_run(
 
     let app = gpui::Application::headless();
     let id = std::process::id().to_string();
+    #[cfg(not(target_os = "freebsd"))]
     app.background_executor()
         .spawn(crashes::init(crashes::InitCrashHandler {
             session_id: id,
@@ -562,6 +563,7 @@ pub(crate) fn execute_proxy(
     let server_paths = ServerPaths::new(&identifier)?;
 
     let id = std::process::id().to_string();
+    #[cfg(not(target_os = "freebsd"))]
     smol::spawn(crashes::init(crashes::InitCrashHandler {
         session_id: id,
         zed_version: VERSION.to_owned(),
