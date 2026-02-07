--- crates/zed/src/reliability.rs.orig	2026-01-29 22:37:26 UTC
+++ crates/zed/src/reliability.rs
@@ -18,6 +18,7 @@ const MAX_HANG_TRACES: usize = 3;
 
 const MAX_HANG_TRACES: usize = 3;
 
+#[cfg(not(target_os = "freebsd"))]
 pub fn init(client: Arc<Client>, cx: &mut App) {
     monitor_hangs(cx);
 
@@ -198,6 +199,7 @@ fn save_hang_trace(
     );
 }
 
+#[cfg(not(target_os = "freebsd"))]
 pub async fn upload_previous_minidumps(client: Arc<Client>) -> anyhow::Result<()> {
     let Some(minidump_endpoint) = MINIDUMP_ENDPOINT.as_ref() else {
         log::warn!("Minidump endpoint not set");
@@ -239,6 +241,7 @@ pub async fn upload_previous_minidumps(client: Arc<Cli
     Ok(())
 }
 
+#[cfg(not(target_os = "freebsd"))]
 async fn upload_minidump(
     client: Arc<Client>,
     endpoint: &str,
