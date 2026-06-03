--- crates/fs/tests/integration/fs.rs.orig	2026-04-23 01:03:50 UTC
+++ crates/fs/tests/integration/fs.rs
@@ -529,7 +529,12 @@ async fn test_rename(executor: BackgroundExecutor) {
 }
 
 #[gpui::test]
-#[cfg(any(target_os = "macos", target_os = "linux", target_os = "windows"))]
+#[cfg(any(
+    target_os = "macos",
+    target_os = "linux",
+    target_os = "windows",
+    target_os = "freebsd"
+))]
 async fn test_realfs_parallel_rename_without_overwrite_preserves_losing_source(
     executor: BackgroundExecutor,
 ) {
@@ -557,7 +562,12 @@ async fn test_realfs_parallel_rename_without_overwrite
 }
 
 #[gpui::test]
-#[cfg(any(target_os = "macos", target_os = "linux", target_os = "windows"))]
+#[cfg(any(
+    target_os = "macos",
+    target_os = "linux",
+    target_os = "windows",
+    target_os = "freebsd"
+))]
 async fn test_realfs_rename_ignore_if_exists_leaves_source_and_target_unchanged(
     executor: BackgroundExecutor,
 ) {
