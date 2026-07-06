--- crates/zed/src/reliability.rs.orig	2026-07-01 15:07:44 UTC
+++ crates/zed/src/reliability.rs
@@ -23,6 +23,7 @@ mod hang_detection;
 
 mod hang_detection;
 
+#[cfg(not(target_os = "freebsd"))]
 pub fn init(client: Arc<Client>, cx: &mut App) {
     hang_detection::start(client.clone(), cx);
     start_memory_usage_logging(cx);
@@ -144,6 +145,7 @@ fn start_memory_usage_logging(cx: &App) {
     .detach();
 }
 
+#[cfg(not(target_os = "freebsd"))]
 pub async fn upload_previous_minidumps(client: Arc<Client>) -> anyhow::Result<()> {
     let Some(minidump_endpoint) = MINIDUMP_ENDPOINT.as_ref() else {
         log::warn!("Minidump endpoint not set");
@@ -185,6 +187,7 @@ pub async fn upload_previous_minidumps(client: Arc<Cli
     Ok(())
 }
 
+#[cfg(not(target_os = "freebsd"))]
 async fn upload_minidump(
     client: Arc<Client>,
     endpoint: &str,
