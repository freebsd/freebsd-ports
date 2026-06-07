--- crates/zed/src/zed.rs.orig	2026-06-06 03:37:40 UTC
+++ crates/zed/src/zed.rs
@@ -105,8 +105,10 @@ const STATUS_URL: &str = "https://status.zed.dev";
 const DOCS_URL: &str = "https://zed.dev/docs/";
 const STATUS_URL: &str = "https://status.zed.dev";
 
+#[cfg(not(target_os = "freebsd"))]
 pub struct CrashHandler(pub Arc<crashes::Client>);
 
+#[cfg(not(target_os = "freebsd"))]
 impl gpui::Global for CrashHandler {}
 
 actions!(
@@ -526,6 +528,7 @@ pub fn initialize_workspace(app_state: Arc<AppState>, 
         if let Some(specs) = window.gpu_specs() {
             log::info!("Using GPU: {:?}", specs);
             show_software_emulation_warning_if_needed(specs.clone(), window, cx);
+            #[cfg(not(target_os = "freebsd"))]
             if let Some(crash_client) = cx.try_global::<CrashHandler>() {
                 crashes::set_gpu_info(&crash_client.0, specs);
             }
