--- crates/gpui/src/gpui.rs.orig	2026-03-04 15:41:56 UTC
+++ crates/gpui/src/gpui.rs
@@ -35,7 +35,7 @@ pub mod profiler;
 pub mod prelude;
 /// Profiling utilities for task timing and thread performance tracking.
 pub mod profiler;
-#[cfg(any(target_os = "windows", target_os = "linux"))]
+#[cfg(any(target_os = "windows", target_os = "linux", target_os = "freebsd"))]
 #[expect(missing_docs)]
 pub mod queue;
 mod scene;
@@ -96,7 +96,7 @@ pub use profiler::*;
 pub use path_builder::*;
 pub use platform::*;
 pub use profiler::*;
-#[cfg(any(target_os = "windows", target_os = "linux"))]
+#[cfg(any(target_os = "windows", target_os = "linux", target_os = "freebsd"))]
 pub use queue::{PriorityQueueReceiver, PriorityQueueSender};
 pub use refineable::*;
 pub use scene::*;
