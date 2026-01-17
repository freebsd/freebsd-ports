--- intercept-preload/src/lib.rs.orig	2026-01-17 08:05:31 UTC
+++ intercept-preload/src/lib.rs
@@ -5,11 +5,11 @@
 //! The library captures system calls and reports them to the collector.
 
 // Only include Linux implementation when building for Linux
-#[cfg(target_os = "linux")]
+#[cfg(any(target_os = "linux", target_os = "freebsd"))]
 mod implementation;
 
 // Re-export Linux implementations when on Linux
-#[cfg(target_os = "linux")]
+#[cfg(any(target_os = "linux", target_os = "freebsd"))]
 pub use implementation::*;
 
 /// Version information for the library
