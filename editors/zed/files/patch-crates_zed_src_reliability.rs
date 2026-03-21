--- crates/zed/src/reliability.rs.orig	2026-03-04 15:41:56 UTC
+++ crates/zed/src/reliability.rs
@@ -21,6 +21,7 @@ const MAX_HANG_TRACES: usize = 3;
 
 const MAX_HANG_TRACES: usize = 3;
 
+#[cfg(not(target_os = "freebsd"))]
 pub fn init(client: Arc<Client>, cx: &mut App) {
     monitor_hangs(cx);
 
@@ -215,6 +216,7 @@ fn save_hang_trace(
     );
 }
 
+#[cfg(not(target_os = "freebsd"))]
 pub async fn upload_previous_minidumps(client: Arc<Client>) -> anyhow::Result<()> {
     let Some(minidump_endpoint) = MINIDUMP_ENDPOINT.as_ref() else {
         log::warn!("Minidump endpoint not set");
@@ -256,6 +258,7 @@ pub async fn upload_previous_minidumps(client: Arc<Cli
     Ok(())
 }
 
+#[cfg(not(target_os = "freebsd"))]
 async fn upload_minidump(
     client: Arc<Client>,
     endpoint: &str,
