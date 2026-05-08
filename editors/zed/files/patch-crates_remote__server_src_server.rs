--- crates/remote_server/src/server.rs.orig	2026-05-06 20:35:33 UTC
+++ crates/remote_server/src/server.rs
@@ -462,6 +462,7 @@ pub fn execute_run(
     let app = gpui_platform::headless();
     let pid = std::process::id();
     let id = pid.to_string();
+    #[cfg(not(target_os = "freebsd"))]
     crashes::init(
         crashes::InitCrashHandler {
             session_id: id,
@@ -720,6 +721,7 @@ pub(crate) fn execute_proxy(
     let server_paths = ServerPaths::new(&identifier)?;
 
     let id = std::process::id().to_string();
+    #[cfg(not(target_os = "freebsd"))]
     crashes::init(
         crashes::InitCrashHandler {
             session_id: id,
