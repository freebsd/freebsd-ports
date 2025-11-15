--- crates/zed/src/reliability.rs.orig	2025-11-15 05:44:38 UTC
+++ crates/zed/src/reliability.rs
@@ -11,6 +11,7 @@ use util::ResultExt;
 use std::{ffi::OsStr, fs, sync::Arc};
 use util::ResultExt;
 
+#[cfg(not(target_os = "freebsd"))]
 pub fn init(http_client: Arc<HttpClientWithUrl>, installation_id: Option<String>, cx: &mut App) {
     #[cfg(target_os = "macos")]
     monitor_main_thread_hangs(http_client.clone(), installation_id.clone(), cx);
@@ -272,6 +273,7 @@ pub fn monitor_main_thread_hangs(
         .detach()
 }
 
+#[cfg(not(target_os = "freebsd"))]
 pub async fn upload_previous_minidumps(
     http: Arc<HttpClientWithUrl>,
     installation_id: Option<String>,
@@ -311,6 +313,7 @@ pub async fn upload_previous_minidumps(
     Ok(())
 }
 
+#[cfg(not(target_os = "freebsd"))]
 async fn upload_minidump(
     http: Arc<HttpClientWithUrl>,
     endpoint: &str,
