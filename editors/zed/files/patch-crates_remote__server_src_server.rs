--- crates/remote_server/src/server.rs.orig	2026-10-23 12:50:45 UTC
+++ crates/remote_server/src/server.rs
@@ -679,6 +679,7 @@ pub fn execute_run(
     let should_install_crash_handler =
         client::telemetry::should_install_crash_handler(*RELEASE_CHANNEL);
 
+    #[cfg(not(target_os = "freebsd"))]
     let crash_handler = if should_install_crash_handler {
         Some(app.background_executor().spawn(crashes::init(
             crashes::InitCrashHandler {
@@ -742,6 +743,7 @@ pub fn execute_run(
 
     let git_hosting_provider_registry = Arc::new(GitHostingProviderRegistry::new());
     let run = move |cx: &mut App| {
+        #[cfg(not(target_os = "freebsd"))]
         if let Some(crash_handler) = crash_handler {
             cx.spawn(async move |_cx| {
                 let _crash_handler = crash_handler.await;
@@ -958,6 +960,7 @@ pub(crate) fn execute_proxy(
         client::telemetry::should_install_crash_handler(*RELEASE_CHANNEL);
 
     if should_install_crash_handler {
+        #[cfg(not(target_os = "freebsd"))]
         smol::spawn(crashes::init(
             crashes::InitCrashHandler {
                 session_id: id,
