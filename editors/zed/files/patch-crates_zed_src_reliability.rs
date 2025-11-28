--- crates/zed/src/reliability.rs.orig	2025-11-27 19:12:04 UTC
+++ crates/zed/src/reliability.rs
@@ -13,6 +13,7 @@ use crate::STARTUP_TIME;
 
 use crate::STARTUP_TIME;
 
+#[cfg(not(target_os = "freebsd"))]
 pub fn init(client: Arc<Client>, cx: &mut App) {
     monitor_hangs(cx);
 
@@ -151,6 +152,7 @@ fn save_hang_trace(
     );
 }
 
+#[cfg(not(target_os = "freebsd"))]
 pub async fn upload_previous_minidumps(client: Arc<Client>) -> anyhow::Result<()> {
     let Some(minidump_endpoint) = MINIDUMP_ENDPOINT.as_ref() else {
         log::warn!("Minidump endpoint not set");
@@ -186,6 +188,7 @@ pub async fn upload_previous_minidumps(client: Arc<Cli
     Ok(())
 }
 
+#[cfg(not(target_os = "freebsd"))]
 async fn upload_minidump(
     client: Arc<Client>,
     endpoint: &str,
