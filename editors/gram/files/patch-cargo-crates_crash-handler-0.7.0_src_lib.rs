--- cargo-crates/crash-handler-0.7.0/src/lib.rs.orig	2006-07-24 01:21:28 UTC
+++ cargo-crates/crash-handler-0.7.0/src/lib.rs
@@ -54,6 +54,7 @@ pub enum CrashEventResult {
     #[cfg(any(
         target_os = "linux",
         target_os = "android",
+        target_os = "freebsd",
         all(target_os = "windows", target_arch = "x86_64"),
     ))]
     /// The handler wishes to jump somewhere else, presumably to return
@@ -182,7 +183,7 @@ cfg_if::cfg_if! {
 }
 
 cfg_if::cfg_if! {
-    if #[cfg(any(target_os = "linux", target_os = "android"))] {
+    if #[cfg(any(target_os = "linux", target_os = "android", target_os = "freebsd"))] {
         mod linux;
 
         pub use linux::{CrashHandler, Signal, jmp};
