Obtained from:  https://github.com/Arc-blroth/memory-stats/commit/ab84d72c6bae5803d1fdb4dbfbc22e6744bafbb5

--- cargo-crates/memory-stats-1.1.0/src/lib.rs.orig	2006-07-24 01:21:28 UTC
+++ cargo-crates/memory-stats-1.1.0/src/lib.rs
@@ -46,11 +46,18 @@ use serde::{Deserialize, Serialize};
 #[cfg(feature = "serde")]
 use serde::{Deserialize, Serialize};
 
-#[cfg_attr(target_os = "windows", path = "windows.rs")]
-#[cfg_attr(any(target_os = "linux", target_os = "android"), path = "linux.rs")]
-#[cfg_attr(any(target_os = "macos", target_os = "ios"), path = "darwin.rs")]
+#[cfg(target_os = "windows")]
+#[path = "windows.rs"]
 mod platform;
 
+#[cfg(any(target_os = "linux", target_os = "android"))]
+#[path = "linux.rs"]
+mod platform;
+
+#[cfg(any(target_os = "macos", target_os = "ios"))]
+#[path = "darwin.rs"]
+mod platform;
+
 #[cfg(not(any(
     target_os = "windows",
     target_os = "linux",
@@ -59,6 +66,8 @@ mod platform {
     target_os = "ios",
 )))]
 mod platform {
+    use crate::MemoryStats;
+
     pub fn memory_stats() -> Option<MemoryStats> {
         None
     }
@@ -91,16 +100,6 @@ pub struct MemoryStats {
 /// If the current memory usage cannot be queried
 /// or `memory_stats` is run on a unsupported platform,
 /// `None` is returned.
-#[cfg_attr(
-    not(any(
-        target_os = "windows",
-        target_os = "linux",
-        target_os = "android",
-        target_os = "macos",
-        target_os = "ios",
-    )),
-    deprecated("memory-stats doesn't support this platform!")
-)]
 pub fn memory_stats() -> Option<MemoryStats> {
     platform::memory_stats()
 }
