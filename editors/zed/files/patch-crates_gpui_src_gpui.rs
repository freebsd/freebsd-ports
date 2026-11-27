--- crates/gpui/src/gpui.rs.orig	2026-11-25 15:48:16 UTC
+++ crates/gpui/src/gpui.rs
@@ -72,6 +72,7 @@ mod hot_reload;
     test,
     target_os = "windows",
     target_os = "linux",
+    target_os = "freebsd",
     target_family = "wasm",
     feature = "test-support",
     feature = "bench-support"
@@ -109,7 +110,7 @@ pub mod private {
     pub use serde_json;
 }
 
-#[cfg(any(target_os = "windows", target_os = "linux", target_family = "wasm"))]
+#[cfg(any(target_os = "windows", target_os = "linux", target_os = "freebsd", target_family = "wasm"))]
 pub use queue::{PriorityQueueReceiver, PriorityQueueSender};
 
 pub use accesskit::{Action as AccessibleAction, Orientation, Role, Toggled};
