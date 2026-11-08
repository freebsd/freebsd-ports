--- cargo-crates/mio-1.0.4/src/sys/unix/selector/kqueue.rs.orig	2026-11-06 02:28:14 UTC
+++ cargo-crates/mio-1.0.4/src/sys/unix/selector/kqueue.rs
@@ -704,7 +704,6 @@ pub mod event {
             ))]
             libc::NOTE_EXIT_DETAIL,
             libc::NOTE_PDATAMASK,
-            libc::NOTE_PCTRLMASK,
             #[cfg(any(
                 target_os = "dragonfly",
                 target_os = "freebsd",
