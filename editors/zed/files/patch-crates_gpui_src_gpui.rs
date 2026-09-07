--- crates/gpui/src/gpui.rs.orig	2026-09-04 14:25:12 UTC
+++ crates/gpui/src/gpui.rs
@@ -42,6 +42,7 @@ pub mod profiler;
     test,
     target_os = "windows",
     target_os = "linux",
+    target_os = "freebsd",
     target_family = "wasm",
     feature = "test-support",
     feature = "bench-support"
@@ -146,7 +147,7 @@ pub use profiler::*;
 pub use path_builder::*;
 pub use platform::*;
 pub use profiler::*;
-#[cfg(any(target_os = "windows", target_os = "linux", target_family = "wasm"))]
+#[cfg(any(target_os = "windows", target_os = "linux", target_os = "freebsd", target_family = "wasm"))]
 pub use queue::{PriorityQueueReceiver, PriorityQueueSender};
 pub use refineable::*;
 pub use scene::*;
