--- crates/remote_server/src/server.rs.orig	2026-05-13 17:09:47 UTC
+++ crates/remote_server/src/server.rs
@@ -467,6 +467,7 @@ pub fn execute_run(
         Ok("true" | "1")
     ) || *RELEASE_CHANNEL != ReleaseChannel::Dev;
 
+    #[cfg(not(target_os = "freebsd"))]
     let crash_handler = if should_install_crash_handler {
         Some(app.background_executor().spawn(crashes::init(
             crashes::InitCrashHandler {
@@ -530,6 +531,7 @@ pub fn execute_run(
 
     let git_hosting_provider_registry = Arc::new(GitHostingProviderRegistry::new());
     let run = move |cx: &mut App| {
+        #[cfg(not(target_os = "freebsd"))]
         if let Some(crash_handler) = crash_handler {
             cx.spawn(async move |_cx| {
                 let _crash_handler = crash_handler.await;
@@ -747,6 +749,7 @@ pub(crate) fn execute_proxy(
     ) || *RELEASE_CHANNEL != ReleaseChannel::Dev;
 
     if should_install_crash_handler {
+        #[cfg(not(target_os = "freebsd"))]
         smol::spawn(crashes::init(
             crashes::InitCrashHandler {
                 session_id: id,
