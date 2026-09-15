--- crates/fs/src/fs_watcher.rs.orig	2026-08-25 07:40:58 UTC
+++ crates/fs/src/fs_watcher.rs
@@ -218,7 +218,7 @@ impl Watcher for FsWatcher {
                 }
             }
         }
-        #[cfg(any(target_os = "linux"))]
+        #[cfg(any(target_os = "linux", target_os = "freebsd"))]
         {
             if self.registrations.lock().contains_key(path) {
                 log::trace!("path to watch is already watched: {path:?}");
