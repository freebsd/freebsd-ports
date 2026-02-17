--- crates/fs/src/fs_watcher.rs.orig	2026-02-11 21:05:23 UTC
+++ crates/fs/src/fs_watcher.rs
@@ -70,7 +70,7 @@ impl Watcher for FsWatcher {
                 return Ok(());
             }
         }
-        #[cfg(target_os = "linux")]
+        #[cfg(any(target_os = "linux", target_os = "freebsd"))]
         {
             if self.registrations.lock().contains_key(path) {
                 log::trace!("path to watch is already watched: {path:?}");
@@ -83,7 +83,7 @@ impl Watcher for FsWatcher {
 
         #[cfg(any(target_os = "windows", target_os = "macos"))]
         let mode = notify::RecursiveMode::Recursive;
-        #[cfg(target_os = "linux")]
+        #[cfg(any(target_os = "linux", target_os = "freebsd"))]
         let mode = notify::RecursiveMode::NonRecursive;
 
         let registration_id = global({
