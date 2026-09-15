--- cargo-crates/minidump-writer-0.12.0/src/lib.rs.orig	2026-09-15 04:07:57 UTC
+++ cargo-crates/minidump-writer-0.12.0/src/lib.rs
@@ -21,6 +21,10 @@ cfg_if::cfg_if! {
         mod mac;
 
         pub use mac::*;
+    } else if #[cfg(target_os = "freebsd")] {
+        mod freebsd;
+
+        pub use freebsd::*;
     }
 }
 
