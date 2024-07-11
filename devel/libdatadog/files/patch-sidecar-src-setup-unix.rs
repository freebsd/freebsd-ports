--- sidecar/src/setup/unix.rs.orig	2024-05-03 17:30:09 UTC
+++ sidecar/src/setup/unix.rs
@@ -111,6 +111,9 @@ impl Default for SharedDirLiaison {
     }
 }
 
+#[cfg(target_os = "freebsd")]
+pub type DefaultLiason = SharedDirLiaison;
+
 #[cfg(target_os = "linux")]
 mod linux {
     use std::{io, os::unix::net::UnixListener, path::PathBuf};
