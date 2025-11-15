--- crates/gpui/examples/layer_shell.rs.orig	2025-11-15 06:20:54 UTC
+++ crates/gpui/examples/layer_shell.rs
@@ -1,12 +1,12 @@ fn main() {
 fn main() {
-    #[cfg(all(target_os = "linux", feature = "wayland"))]
+    #[cfg(all(any(target_os = "linux", target_os = "freebsd"), feature = "wayland"))]
     example::main();
 
-    #[cfg(not(all(target_os = "linux", feature = "wayland")))]
+    #[cfg(not(all(any(target_os = "linux", target_os = "freebsd"), feature = "wayland")))]
     panic!("This example requires the `wayland` feature and a linux system.");
 }
 
-#[cfg(all(target_os = "linux", feature = "wayland"))]
+#[cfg(all(any(target_os = "linux", target_os = "freebsd"), feature = "wayland"))]
 mod example {
     use std::time::{Duration, SystemTime, UNIX_EPOCH};
 
