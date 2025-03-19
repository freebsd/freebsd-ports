--- crashtracker/src/collector/crash_handler.rs.orig	2025-02-11 17:46:31 UTC
+++ crashtracker/src/collector/crash_handler.rs
@@ -48,7 +48,7 @@ use std::time::{Duration, Instant};
 // Macos seems to have deprecated vfork.  The reason to prefer vfork is to suppress atfork
 // handlers.  This is OK because macos is primarily a test platform, and we have system-level
 // testing on Linux in various CI environments.
-#[cfg(target_os = "macos")]
+#[cfg(any(target_os = "freebsd", target_os = "macos"))]
 use libc::fork as vfork;
 
 #[cfg(target_os = "linux")]
