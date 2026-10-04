--- crates/fs/tests/integration/fs_tests.rs.orig	2026-10-04 12:55:16 UTC
+++ crates/fs/tests/integration/fs_tests.rs
@@ -582,7 +582,7 @@ async fn test_rename(executor: BackgroundExecutor) {
 }
 
 #[gpui::test]
-#[cfg(any(target_os = "macos", target_os = "linux", target_os = "windows"))]
+#[cfg(any(target_os = "macos", target_os = "linux", target_os = "windows", target_os = "freebsd"))]
 async fn test_realfs_parallel_rename_without_overwrite_preserves_losing_source(
     executor: BackgroundExecutor,
 ) {
@@ -610,7 +610,7 @@ async fn test_realfs_parallel_rename_without_overwrite
 }
 
 #[gpui::test]
-#[cfg(any(target_os = "macos", target_os = "linux", target_os = "windows"))]
+#[cfg(any(target_os = "macos", target_os = "linux", target_os = "windows", target_os = "freebsd"))]
 async fn test_realfs_rename_ignore_if_exists_leaves_source_and_target_unchanged(
     executor: BackgroundExecutor,
 ) {
@@ -744,7 +744,7 @@ async fn assert_remove_file_unlinks_symlink(root: &Pat
 }
 
 #[gpui::test]
-#[cfg(any(target_os = "macos", target_os = "linux", target_os = "windows"))]
+#[cfg(any(target_os = "macos", target_os = "linux", target_os = "windows", target_os = "freebsd"))]
 async fn test_realfs_copy_and_remove_semantics(cx: &mut TestAppContext) {
     cx.executor().allow_parking();
     let executor = cx.executor();
