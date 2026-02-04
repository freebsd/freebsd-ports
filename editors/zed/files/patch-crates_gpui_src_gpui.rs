--- crates/gpui/src/gpui.rs.orig	2026-01-29 22:37:26 UTC
+++ crates/gpui/src/gpui.rs
@@ -33,7 +33,7 @@ mod profiler;
 mod platform;
 pub mod prelude;
 mod profiler;
-#[cfg(any(target_os = "windows", target_os = "linux"))]
+#[cfg(any(target_os = "windows", target_os = "linux", target_os = "freebsd"))]
 mod queue;
 mod scene;
 mod shared_string;
@@ -93,7 +93,7 @@ pub use profiler::*;
 pub use path_builder::*;
 pub use platform::*;
 pub use profiler::*;
-#[cfg(any(target_os = "windows", target_os = "linux"))]
+#[cfg(any(target_os = "windows", target_os = "linux", target_os = "freebsd"))]
 pub(crate) use queue::{PriorityQueueReceiver, PriorityQueueSender};
 pub use refineable::*;
 pub use scene::*;
