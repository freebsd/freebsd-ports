--- crates/gpui/src/gpui.rs.orig	2026-01-10 05:46:21 UTC
+++ crates/gpui/src/gpui.rs
@@ -31,7 +31,7 @@ mod profiler;
 mod platform;
 pub mod prelude;
 mod profiler;
-#[cfg(target_os = "linux")]
+#[cfg(any(target_os = "linux", target_os = "freebsd"))]
 mod queue;
 mod scene;
 mod shared_string;
@@ -91,7 +91,7 @@ pub use profiler::*;
 pub use path_builder::*;
 pub use platform::*;
 pub use profiler::*;
-#[cfg(target_os = "linux")]
+#[cfg(any(target_os = "linux", target_os = "freebsd"))]
 pub(crate) use queue::{PriorityQueueReceiver, PriorityQueueSender};
 pub use refineable::*;
 pub use scene::*;
