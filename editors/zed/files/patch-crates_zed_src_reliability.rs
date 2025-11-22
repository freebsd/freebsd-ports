--- crates/zed/src/reliability.rs.orig	2025-11-19 15:41:44 UTC
+++ crates/zed/src/reliability.rs
@@ -14,6 +14,7 @@ use crate::STARTUP_TIME;
 
 use crate::STARTUP_TIME;
 
+#[cfg(not(target_os = "freebsd"))]
 pub fn init(http_client: Arc<HttpClientWithUrl>, installation_id: Option<String>, cx: &mut App) {
     monitor_hangs(cx);
 
@@ -365,6 +366,7 @@ fn save_hang_trace(
     );
 }
 
+#[cfg(not(target_os = "freebsd"))]
 pub async fn upload_previous_minidumps(
     http: Arc<HttpClientWithUrl>,
     installation_id: Option<String>,
@@ -404,6 +406,7 @@ pub async fn upload_previous_minidumps(
     Ok(())
 }
 
+#[cfg(not(target_os = "freebsd"))]
 async fn upload_minidump(
     http: Arc<HttpClientWithUrl>,
     endpoint: &str,
