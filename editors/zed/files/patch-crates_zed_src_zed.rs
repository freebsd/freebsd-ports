--- crates/zed/src/zed.rs.orig	2026-05-13 17:09:47 UTC
+++ crates/zed/src/zed.rs
@@ -102,8 +102,10 @@ use zed_actions::{
     OpenZedUrl, Quit,
 };
 
+#[cfg(not(target_os = "freebsd"))]
 pub struct CrashHandler(pub Arc<crashes::Client>);
 
+#[cfg(not(target_os = "freebsd"))]
 impl gpui::Global for CrashHandler {}
 
 actions!(
@@ -523,6 +525,7 @@ pub fn initialize_workspace(app_state: Arc<AppState>, 
         if let Some(specs) = window.gpu_specs() {
             log::info!("Using GPU: {:?}", specs);
             show_software_emulation_warning_if_needed(specs.clone(), window, cx);
+            #[cfg(not(target_os = "freebsd"))]
             if let Some(crash_client) = cx.try_global::<CrashHandler>() {
                 crashes::set_gpu_info(&crash_client.0, specs);
             }
