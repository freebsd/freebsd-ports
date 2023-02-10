--- ddtelemetry/src/ipc/setup/unix.rs.orig	2022-12-12 17:34:51 UTC
+++ ddtelemetry/src/ipc/setup/unix.rs
@@ -161,6 +161,9 @@ mod linux {
     }
 }
 
+#[cfg(target_os = "freebsd")]
+pub type DefaultLiason = SharedDirLiaison;
+
 #[cfg(target_os = "linux")]
 pub use linux::*;
 
