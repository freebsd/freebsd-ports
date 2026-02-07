--- spawn_worker/src/unix/spawn.rs.orig	2024-05-03 17:30:09 UTC
+++ spawn_worker/src/unix/spawn.rs
@@ -605,6 +605,9 @@ impl Child {
     }
 }
 
+#[cfg(target_os = "freebsd")]
+const SELF_FD_DIR: &str = "/dev/fd";
+
 #[cfg(target_os = "macos")]
 const SELF_FD_DIR: &str = "/dev/fd";
 
