--- crates/project/tests/integration/project_tests.rs.orig	2026-05-06 20:35:33 UTC
+++ crates/project/tests/integration/project_tests.rs
@@ -5881,7 +5881,7 @@ async fn test_rescan_and_remote_updates(cx: &mut gpui:
     });
 }
 
-#[cfg(target_os = "linux")]
+#[cfg(any(target_os = "linux", target_os = "freebsd"))]
 #[gpui::test(retries = 5)]
 async fn test_recreated_directory_receives_child_events(cx: &mut gpui::TestAppContext) {
     init_test(cx);
