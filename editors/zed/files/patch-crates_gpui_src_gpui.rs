--- crates/gpui/src/gpui.rs.orig	2026-11-04 15:12:45 UTC
+++ crates/gpui/src/gpui.rs
@@ -71,6 +71,7 @@ mod hot_reload;
     test,
     target_os = "windows",
     target_os = "linux",
+    target_os = "freebsd",
     target_family = "wasm",
     feature = "test-support",
     feature = "bench-support"
@@ -108,7 +109,7 @@ pub mod private {
     pub use serde_json;
 }
 
-#[cfg(any(target_os = "windows", target_os = "linux", target_family = "wasm"))]
+#[cfg(any(target_os = "windows", target_os = "linux", target_os = "freebsd", target_family = "wasm"))]
 pub use queue::{PriorityQueueReceiver, PriorityQueueSender};
 
 pub use accesskit::{Action as AccessibleAction, Orientation, Role, Toggled};
