--- crates/gpui/src/gpui.rs.orig	2026-03-11 14:31:09 UTC
+++ crates/gpui/src/gpui.rs
@@ -35,7 +35,7 @@ pub mod profiler;
 pub mod prelude;
 /// Profiling utilities for task timing and thread performance tracking.
 pub mod profiler;
-#[cfg(any(target_os = "windows", target_os = "linux", target_family = "wasm"))]
+#[cfg(any(target_os = "windows", target_os = "linux", target_os = "freebsd", target_family = "wasm"))]
 #[expect(missing_docs)]
 pub mod queue;
 mod scene;
@@ -97,7 +97,7 @@ pub use profiler::*;
 pub use path_builder::*;
 pub use platform::*;
 pub use profiler::*;
-#[cfg(any(target_os = "windows", target_os = "linux", target_family = "wasm"))]
+#[cfg(any(target_os = "windows", target_os = "linux", target_os = "freebsd", target_family = "wasm"))]
 pub use queue::{PriorityQueueReceiver, PriorityQueueSender};
 pub use refineable::*;
 pub use scene::*;
