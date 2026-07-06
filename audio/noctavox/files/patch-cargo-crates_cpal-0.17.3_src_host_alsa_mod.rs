--- cargo-crates/cpal-0.17.3/src/host/alsa/mod.rs.orig	2026-06-22 08:56:54 UTC
+++ cargo-crates/cpal-0.17.3/src/host/alsa/mod.rs
@@ -1106,11 +1106,8 @@ fn timespec_to_nanos(ts: libc::timespec) -> i64 {
 // https://fossies.org/linux/alsa-lib/test/audio_time.c
 #[inline]
 fn timespec_to_nanos(ts: libc::timespec) -> i64 {
-    let nanos = ts.tv_sec * 1_000_000_000 + ts.tv_nsec;
-    #[cfg(target_pointer_width = "64")]
+    let nanos = ts.tv_sec as i64 * 1_000_000_000 + ts.tv_nsec as i64;
     return nanos;
-    #[cfg(not(target_pointer_width = "64"))]
-    return nanos.into();
 }
 
 // Adapted from `timediff` here:
