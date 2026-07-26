--- crates/project/tests/integration/project_tests.rs.orig	2026-07-22 23:04:41 UTC
+++ crates/project/tests/integration/project_tests.rs
@@ -67,7 +67,7 @@ use settings::SettingsStore;
 use rand::{Rng as _, rngs::StdRng};
 use serde_json::json;
 use settings::SettingsStore;
-#[cfg(target_os = "linux")]
+#[cfg(any(target_os = "linux", target_os = "freebsd"))]
 use settings::{LocalSettingsKind, LocalSettingsPath};
 #[cfg(not(windows))]
 use std::os;
@@ -6543,7 +6543,7 @@ async fn test_rescan_and_remote_updates(cx: &mut gpui:
     });
 }
 
-#[cfg(target_os = "linux")]
+#[cfg(any(target_os = "linux", target_os = "freebsd"))]
 #[gpui::test(retries = 5)]
 async fn test_recreated_directory_receives_child_events(cx: &mut gpui::TestAppContext) {
     init_test(cx);
@@ -12563,7 +12563,7 @@ async fn test_git_repository_status_removes_directory_
     });
 }
 
-#[cfg(target_os = "linux")]
+#[cfg(any(target_os = "linux", target_os = "freebsd"))]
 #[gpui::test(retries = 5)]
 async fn test_git_events_after_project_excludes_dot_git(cx: &mut gpui::TestAppContext) {
     init_test(cx);
@@ -15251,7 +15251,7 @@ fn git_reset(offset: usize, work_dir: &Path) {
     );
 }
 
-#[cfg(target_os = "linux")]
+#[cfg(any(target_os = "linux", target_os = "freebsd"))]
 #[allow(clippy::disallowed_methods)]
 #[track_caller]
 fn git_branch(name: &str, work_dir: &Path) {
@@ -15266,7 +15266,7 @@ fn git_branch(name: &str, work_dir: &Path) {
     );
 }
 
-#[cfg(target_os = "linux")]
+#[cfg(any(target_os = "linux", target_os = "freebsd"))]
 #[allow(clippy::disallowed_methods)]
 #[track_caller]
 fn git_checkout(name: &str, work_dir: &Path) {
