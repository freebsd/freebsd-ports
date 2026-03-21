--- crates/gpui/examples/layer_shell.rs.orig	2026-03-11 14:31:09 UTC
+++ crates/gpui/examples/layer_shell.rs
@@ -1,10 +1,10 @@ fn run_example() {
 #![cfg_attr(target_family = "wasm", no_main)]
 
 fn run_example() {
-    #[cfg(all(target_os = "linux", feature = "wayland"))]
+    #[cfg(all(any(target_os = "linux", target_os = "freebsd"), feature = "wayland"))]
     example::main();
 
-    #[cfg(not(all(target_os = "linux", feature = "wayland")))]
+    #[cfg(not(all(any(target_os = "linux", target_os = "freebsd"), feature = "wayland")))]
     panic!("This example requires the `wayland` feature and a linux system.");
 }
 
@@ -20,7 +20,7 @@ pub fn start() {
     run_example();
 }
 
-#[cfg(all(target_os = "linux", feature = "wayland"))]
+#[cfg(all(any(target_os = "linux", target_os = "freebsd"), feature = "wayland"))]
 mod example {
     use std::time::{Duration, SystemTime, UNIX_EPOCH};
 
