--- crates/remote_server/src/server.rs.orig	2026-06-06 03:37:40 UTC
+++ crates/remote_server/src/server.rs
@@ -548,6 +548,7 @@ pub fn execute_run(
         Ok("true" | "1")
     ) || *RELEASE_CHANNEL != ReleaseChannel::Dev;
 
+    #[cfg(not(target_os = "freebsd"))]
     let crash_handler = if should_install_crash_handler {
         Some(app.background_executor().spawn(crashes::init(
             crashes::InitCrashHandler {
@@ -611,6 +612,7 @@ pub fn execute_run(
 
     let git_hosting_provider_registry = Arc::new(GitHostingProviderRegistry::new());
     let run = move |cx: &mut App| {
+        #[cfg(not(target_os = "freebsd"))]
         if let Some(crash_handler) = crash_handler {
             cx.spawn(async move |_cx| {
                 let _crash_handler = crash_handler.await;
@@ -828,6 +830,7 @@ pub(crate) fn execute_proxy(
     ) || *RELEASE_CHANNEL != ReleaseChannel::Dev;
 
     if should_install_crash_handler {
+        #[cfg(not(target_os = "freebsd"))]
         smol::spawn(crashes::init(
             crashes::InitCrashHandler {
                 session_id: id,
