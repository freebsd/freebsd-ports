--- crates/zed/src/reliability.rs.orig	2026-01-08 00:39:18 UTC
+++ crates/zed/src/reliability.rs
@@ -16,6 +16,7 @@ use crate::STARTUP_TIME;
 
 use crate::STARTUP_TIME;
 
+#[cfg(not(target_os = "freebsd"))]
 pub fn init(client: Arc<Client>, cx: &mut App) {
     monitor_hangs(cx);
 
@@ -154,6 +155,7 @@ fn save_hang_trace(
     );
 }
 
+#[cfg(not(target_os = "freebsd"))]
 pub async fn upload_previous_minidumps(client: Arc<Client>) -> anyhow::Result<()> {
     let Some(minidump_endpoint) = MINIDUMP_ENDPOINT.as_ref() else {
         log::warn!("Minidump endpoint not set");
@@ -195,6 +197,7 @@ pub async fn upload_previous_minidumps(client: Arc<Cli
     Ok(())
 }
 
+#[cfg(not(target_os = "freebsd"))]
 async fn upload_minidump(
     client: Arc<Client>,
     endpoint: &str,
