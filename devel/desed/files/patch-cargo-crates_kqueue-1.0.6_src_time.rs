--- cargo-crates/kqueue-1.0.6/src/time.rs.orig	1973-11-29 21:33:09 UTC
+++ cargo-crates/kqueue-1.0.6/src/time.rs
@@ -1,32 +1,14 @@
-use libc::timespec;
+use libc::{c_long, time_t, timespec};
 use std::time::Duration;
 
-#[cfg(not(all(
-    any(target_os = "freebsd", target_os = "macos"),
-    any(target_arch = "x86", target_arch = "powerpc")
-)))]
-pub(crate) fn duration_to_timespec(d: Duration) -> timespec {
-    let tv_sec = d.as_secs() as i64;
-    let tv_nsec = d.subsec_nanos() as i64;
+#[cfg(all(target_arch = "x86_64", target_pointer_width = "32"))]
+type NSec = i64;
+#[cfg(not(all(target_arch = "x86_64", target_pointer_width = "32")))]
+type NSec = c_long;
 
-    if tv_sec.is_negative() {
-        panic!("Duration seconds is negative");
-    }
-
-    if tv_nsec.is_negative() {
-        panic!("Duration nsecs is negative");
-    }
-
-    timespec { tv_sec, tv_nsec }
-}
-
-#[cfg(all(
-    any(target_os = "freebsd", target_os = "macos"),
-    any(target_arch = "x86", target_arch = "powerpc")
-))]
 pub(crate) fn duration_to_timespec(d: Duration) -> timespec {
-    let tv_sec = d.as_secs() as i32;
-    let tv_nsec = d.subsec_nanos() as i32;
+    let tv_sec = d.as_secs() as time_t;
+    let tv_nsec = d.subsec_nanos() as NSec;
 
     if tv_sec.is_negative() {
         panic!("Duration seconds is negative");
