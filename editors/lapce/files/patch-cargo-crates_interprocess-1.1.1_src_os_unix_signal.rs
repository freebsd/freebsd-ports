--- cargo-crates/interprocess-1.1.1/src/os/unix/signal.rs.orig	2022-09-05 13:24:51 UTC
+++ cargo-crates/interprocess-1.1.1/src/os/unix/signal.rs
@@ -972,10 +972,10 @@ pub enum SignalType {
     ///
     /// *Default handler: process termination.*
     // TODO more on this
-    #[cfg(any(doc, not(any(target_os = "macos", target_os = "ios",)),))]
+    #[cfg(any(doc, not(any(target_os = "freebsd", target_os = "macos", target_os = "ios",)),))]
     #[cfg_attr(
         feature = "doc_cfg",
-        doc(cfg(not(any(target_os = "macos", target_os = "ios",)),))
+        doc(cfg(not(any(target_os = "freebsd", target_os = "macos", target_os = "ios",)),))
     )]
     PollNotification = SIGPOLL,
     /// `SIGBUS` — [bus error]. This signal is issued by the OS when a process does one of the following:
