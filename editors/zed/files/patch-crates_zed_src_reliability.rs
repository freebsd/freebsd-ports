--- crates/zed/src/reliability.rs.orig	2026-09-17 04:10:36 UTC
+++ crates/zed/src/reliability.rs
@@ -29,6 +29,7 @@ type ProjectRegistry = Rc<RefCell<Vec<WeakEntity<Proje
 
 type ProjectRegistry = Rc<RefCell<Vec<WeakEntity<Project>>>>;
 
+#[cfg(not(target_os = "freebsd"))]
 pub fn init(client: Arc<Client>, workspace_store: Entity<WorkspaceStore>, cx: &mut App) {
     hang_detection::start(client.clone(), cx);
     let projects = ProjectRegistry::default();
@@ -256,6 +257,7 @@ fn log_worktree_diagnostics(
     }
 }
 
+#[cfg(not(target_os = "freebsd"))]
 pub async fn upload_previous_minidumps(client: Arc<Client>) -> anyhow::Result<()> {
     let Some(minidump_endpoint) = MINIDUMP_ENDPOINT.as_ref() else {
         log::warn!("Minidump endpoint not set");
@@ -297,6 +299,7 @@ pub async fn upload_previous_minidumps(client: Arc<Cli
     Ok(())
 }
 
+#[cfg(not(target_os = "freebsd"))]
 async fn upload_minidump(
     client: Arc<Client>,
     endpoint: &str,
