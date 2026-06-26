--- crates/zed/src/zed.rs.orig	2026-06-24 15:32:03 UTC
+++ crates/zed/src/zed.rs
@@ -108,8 +108,10 @@ const STATUS_URL: &str = "https://status.zed.dev";
 const DOCS_URL: &str = "https://zed.dev/docs/";
 const STATUS_URL: &str = "https://status.zed.dev";
 
+#[cfg(not(target_os = "freebsd"))]
 pub struct CrashHandler(pub Arc<crashes::Client>);
 
+#[cfg(not(target_os = "freebsd"))]
 impl gpui::Global for CrashHandler {}
 
 actions!(
@@ -545,6 +547,7 @@ pub fn initialize_workspace(app_state: Arc<AppState>, 
         if let Some(specs) = window.gpu_specs() {
             log::info!("Using GPU: {:?}", specs);
             show_software_emulation_warning_if_needed(specs.clone(), window, cx);
+            #[cfg(not(target_os = "freebsd"))]
             if let Some(crash_client) = cx.try_global::<CrashHandler>() {
                 crashes::set_gpu_info(&crash_client.0, specs);
             }
