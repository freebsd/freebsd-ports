--- crates/project/tests/integration/project_tests.rs.orig	2026-10-14 15:50:18 UTC
+++ crates/project/tests/integration/project_tests.rs
@@ -68,7 +68,7 @@ use settings::{GlobalLspSettingsContent, SettingsStore
 use rand::{Rng as _, rngs::StdRng};
 use serde_json::json;
 use settings::{GlobalLspSettingsContent, SettingsStore, SplicingVec};
-#[cfg(target_os = "linux")]
+#[cfg(any(target_os = "linux", target_os = "freebsd"))]
 use settings::{LocalSettingsKind, LocalSettingsPath};
 #[cfg(not(windows))]
 use std::os;
@@ -85,7 +85,7 @@ use std::{
     task::Poll,
     time::Duration,
 };
-#[cfg(target_os = "linux")]
+#[cfg(any(target_os = "linux", target_os = "freebsd"))]
 use std::{ffi::OsStr, os::unix::ffi::OsStrExt as _};
 use sum_tree::SumTree;
 use task::{ResolvedTask, ShellKind, TaskContext};
@@ -364,7 +364,7 @@ async fn test_resolve_abs_file_link_project_aliases(cx
     });
 }
 
-#[cfg(target_os = "linux")]
+#[cfg(any(target_os = "linux", target_os = "freebsd"))]
 #[gpui::test]
 async fn test_resolve_abs_file_link_rejects_non_utf8_target(cx: &mut gpui::TestAppContext) {
     init_test(cx);
@@ -9127,7 +9127,7 @@ async fn test_rescan_and_remote_updates(cx: &mut gpui:
     });
 }
 
-#[cfg(target_os = "linux")]
+#[cfg(any(target_os = "linux", target_os = "freebsd"))]
 #[gpui::test(retries = 5)]
 async fn test_recreated_directory_receives_child_events(cx: &mut gpui::TestAppContext) {
     init_test(cx);
@@ -17619,7 +17619,7 @@ async fn test_git_repository_status_removes_directory_
     });
 }
 
-#[cfg(target_os = "linux")]
+#[cfg(any(target_os = "linux", target_os = "freebsd"))]
 #[gpui::test(retries = 5)]
 async fn test_git_events_after_project_excludes_dot_git(cx: &mut gpui::TestAppContext) {
     init_test(cx);
@@ -20468,7 +20468,7 @@ fn git_reset(offset: usize, work_dir: &Path) {
     );
 }
 
-#[cfg(target_os = "linux")]
+#[cfg(any(target_os = "linux", target_os = "freebsd"))]
 #[allow(clippy::disallowed_methods)]
 #[track_caller]
 fn git_branch(name: &str, work_dir: &Path) {
@@ -20483,7 +20483,7 @@ fn git_branch(name: &str, work_dir: &Path) {
     );
 }
 
-#[cfg(target_os = "linux")]
+#[cfg(any(target_os = "linux", target_os = "freebsd"))]
 #[allow(clippy::disallowed_methods)]
 #[track_caller]
 fn git_checkout(name: &str, work_dir: &Path) {
