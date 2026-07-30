--- crates/zed/src/reliability.rs.orig	2026-07-29 14:43:24 UTC
+++ crates/zed/src/reliability.rs
@@ -25,6 +25,7 @@ mod hang_detection;
 
 mod hang_detection;
 
+#[cfg(not(target_os = "freebsd"))]
 pub fn init(client: Arc<Client>, workspace_store: Entity<WorkspaceStore>, cx: &mut App) {
     hang_detection::start(client.clone(), cx);
     start_memory_usage_logging(workspace_store, cx);
@@ -229,6 +230,7 @@ fn log_worktree_diagnostics(workspace_store: &Entity<W
     }
 }
 
+#[cfg(not(target_os = "freebsd"))]
 pub async fn upload_previous_minidumps(client: Arc<Client>) -> anyhow::Result<()> {
     let Some(minidump_endpoint) = MINIDUMP_ENDPOINT.as_ref() else {
         log::warn!("Minidump endpoint not set");
@@ -270,6 +272,7 @@ pub async fn upload_previous_minidumps(client: Arc<Cli
     Ok(())
 }
 
+#[cfg(not(target_os = "freebsd"))]
 async fn upload_minidump(
     client: Arc<Client>,
     endpoint: &str,
