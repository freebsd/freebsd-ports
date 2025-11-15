--- crates/fs/src/fs_watcher.rs.orig	2025-11-15 04:58:18 UTC
+++ crates/fs/src/fs_watcher.rs
@@ -70,7 +70,7 @@ impl Watcher for FsWatcher {
                 return Ok(());
             }
         }
-        #[cfg(target_os = "linux")]
+        #[cfg(any(target_os = "linux", target_os = "freebsd"))]
         {
             log::trace!("path to watch is already watched: {path:?}");
             if self.registrations.lock().contains_key(path) {
@@ -83,7 +83,7 @@ impl Watcher for FsWatcher {
 
         #[cfg(target_os = "windows")]
         let mode = notify::RecursiveMode::Recursive;
-        #[cfg(target_os = "linux")]
+        #[cfg(any(target_os = "linux", target_os = "freebsd"))]
         let mode = notify::RecursiveMode::NonRecursive;
 
         let registration_id = global({
