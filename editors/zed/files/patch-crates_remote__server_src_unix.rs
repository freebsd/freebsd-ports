--- crates/remote_server/src/unix.rs.orig	2026-01-08 00:39:18 UTC
+++ crates/remote_server/src/unix.rs
@@ -358,6 +358,7 @@ pub fn execute_run(
 
     let app = gpui::Application::headless();
     let id = std::process::id().to_string();
+    #[cfg(not(target_os = "freebsd"))]
     app.background_executor()
         .spawn(crashes::init(crashes::InitCrashHandler {
             session_id: id,
@@ -585,6 +586,7 @@ pub(crate) fn execute_proxy(
     let server_paths = ServerPaths::new(&identifier)?;
 
     let id = std::process::id().to_string();
+    #[cfg(not(target_os = "freebsd"))]
     smol::spawn(crashes::init(crashes::InitCrashHandler {
         session_id: id,
         zed_version: VERSION.to_owned(),
