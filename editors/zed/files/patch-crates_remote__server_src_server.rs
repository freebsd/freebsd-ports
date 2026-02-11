--- crates/remote_server/src/server.rs.orig	2026-02-10 14:24:33 UTC
+++ crates/remote_server/src/server.rs
@@ -450,6 +450,7 @@ pub fn execute_run(
     let app = gpui::Application::headless();
     let pid = std::process::id();
     let id = pid.to_string();
+    #[cfg(not(target_os = "freebsd"))]
     app.background_executor()
         .spawn(crashes::init(crashes::InitCrashHandler {
             session_id: id,
@@ -701,6 +702,7 @@ pub(crate) fn execute_proxy(
     let server_paths = ServerPaths::new(&identifier)?;
 
     let id = std::process::id().to_string();
+    #[cfg(not(target_os = "freebsd"))]
     smol::spawn(crashes::init(crashes::InitCrashHandler {
         session_id: id,
         zed_version: VERSION.to_owned(),
