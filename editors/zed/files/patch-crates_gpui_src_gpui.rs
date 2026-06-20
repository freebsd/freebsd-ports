--- crates/gpui/src/gpui.rs.orig	2026-06-17 14:36:18 UTC
+++ crates/gpui/src/gpui.rs
@@ -39,6 +39,7 @@ pub mod profiler;
     test,
     target_os = "windows",
     target_os = "linux",
+    target_os = "freebsd",
     target_family = "wasm",
     feature = "bench"
 ))]
@@ -137,7 +138,7 @@ pub use profiler::*;
 pub use path_builder::*;
 pub use platform::*;
 pub use profiler::*;
-#[cfg(any(target_os = "windows", target_os = "linux", target_family = "wasm"))]
+#[cfg(any(target_os = "windows", target_os = "linux", target_os = "freebsd", target_family = "wasm"))]
 pub use queue::{PriorityQueueReceiver, PriorityQueueSender};
 pub use refineable::*;
 pub use scene::*;
