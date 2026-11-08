--- cargo-crates/mio-1.2.2/src/sys/unix/selector/kqueue.rs.orig	2006-07-24 01:21:28 UTC
+++ cargo-crates/mio-1.2.2/src/sys/unix/selector/kqueue.rs
@@ -734,7 +734,6 @@ pub mod event {
             ))]
             libc::NOTE_EXIT_DETAIL,
             libc::NOTE_PDATAMASK,
-            libc::NOTE_PCTRLMASK,
             #[cfg(any(
                 target_os = "dragonfly",
                 target_os = "freebsd",
