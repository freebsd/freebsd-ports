--- crates/remote_server/src/server.rs.orig	2026-03-04 15:41:56 UTC
+++ crates/remote_server/src/server.rs
@@ -452,6 +452,7 @@ pub fn execute_run(
     let app = gpui_platform::headless();
     let pid = std::process::id();
     let id = pid.to_string();
+    #[cfg(not(target_os = "freebsd"))]
     crashes::init(
         crashes::InitCrashHandler {
             session_id: id,
@@ -707,6 +708,7 @@ pub(crate) fn execute_proxy(
     let server_paths = ServerPaths::new(&identifier)?;
 
     let id = std::process::id().to_string();
+    #[cfg(not(target_os = "freebsd"))]
     crashes::init(
         crashes::InitCrashHandler {
             session_id: id,
