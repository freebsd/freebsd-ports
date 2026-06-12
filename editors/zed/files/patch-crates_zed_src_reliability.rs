--- crates/zed/src/reliability.rs.orig	2026-06-10 17:21:09 UTC
+++ crates/zed/src/reliability.rs
@@ -18,6 +18,7 @@ mod hang_detection;
 
 mod hang_detection;
 
+#[cfg(not(target_os = "freebsd"))]
 pub fn init(client: Arc<Client>, cx: &mut App) {
     hang_detection::start(client.clone(), cx);
 
@@ -82,6 +83,7 @@ pub fn init(client: Arc<Client>, cx: &mut App) {
     .detach();
 }
 
+#[cfg(not(target_os = "freebsd"))]
 pub async fn upload_previous_minidumps(client: Arc<Client>) -> anyhow::Result<()> {
     let Some(minidump_endpoint) = MINIDUMP_ENDPOINT.as_ref() else {
         log::warn!("Minidump endpoint not set");
@@ -123,6 +125,7 @@ pub async fn upload_previous_minidumps(client: Arc<Cli
     Ok(())
 }
 
+#[cfg(not(target_os = "freebsd"))]
 async fn upload_minidump(
     client: Arc<Client>,
     endpoint: &str,
