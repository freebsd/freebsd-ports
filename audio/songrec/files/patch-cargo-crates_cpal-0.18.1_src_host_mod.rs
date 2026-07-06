--- cargo-crates/cpal-0.18.1/src/host/mod.rs.orig	2026-06-14 22:13:07 UTC
+++ cargo-crates/cpal-0.18.1/src/host/mod.rs
@@ -226,6 +226,9 @@ pub(crate) use error_emit::try_emit_error;
 /// Convert a frame count at a given sample rate to a [`std::time::Duration`].
 #[cfg(any(
     target_os = "linux",
+    target_os = "dragonfly",
+    target_os = "freebsd",
+    target_os = "netbsd",
     target_os = "windows",
     target_vendor = "apple",
     feature = "audioworklet",
