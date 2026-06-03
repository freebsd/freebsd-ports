--- cargo-crates/crash-context-0.6.3/src/lib.rs.orig	2006-07-24 01:21:28 UTC
+++ cargo-crates/crash-context-0.6.3/src/lib.rs
@@ -34,5 +34,8 @@ cfg_if::cfg_if! {
     } else if #[cfg(target_os = "macos")] {
         mod mac;
         pub use mac::*;
+    } else if #[cfg(target_os = "freebsd")] {
+        mod freebsd;
+        pub use freebsd::*;
     }
 }
