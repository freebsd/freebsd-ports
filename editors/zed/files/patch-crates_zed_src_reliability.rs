--- crates/zed/src/reliability.rs.orig	2026-04-10 01:17:11 UTC
+++ crates/zed/src/reliability.rs
@@ -21,6 +21,7 @@ const MAX_HANG_TRACES: usize = 3;
 
 const MAX_HANG_TRACES: usize = 3;
 
+#[cfg(not(target_os = "freebsd"))]
 pub fn init(client: Arc<Client>, cx: &mut App) {
     if cfg!(debug_assertions) {
         log::info!("Debug assertions enabled, skipping hang monitoring");
@@ -219,6 +220,7 @@ fn save_hang_trace(
     );
 }
 
+#[cfg(not(target_os = "freebsd"))]
 pub async fn upload_previous_minidumps(client: Arc<Client>) -> anyhow::Result<()> {
     let Some(minidump_endpoint) = MINIDUMP_ENDPOINT.as_ref() else {
         log::warn!("Minidump endpoint not set");
@@ -260,6 +262,7 @@ pub async fn upload_previous_minidumps(client: Arc<Cli
     Ok(())
 }
 
+#[cfg(not(target_os = "freebsd"))]
 async fn upload_minidump(
     client: Arc<Client>,
     endpoint: &str,
