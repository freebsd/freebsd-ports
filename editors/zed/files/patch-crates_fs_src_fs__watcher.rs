--- crates/fs/src/fs_watcher.rs.orig	2026-06-06 03:37:40 UTC
+++ crates/fs/src/fs_watcher.rs
@@ -173,8 +173,13 @@ pub fn requires_poll_watcher(path: &Path) -> bool {
         return detect_requires_poll_watcher_linux(path);
     }
 
-    #[cfg(not(target_os = "linux"))]
+    #[cfg(target_os = "freebsd")]
     {
+        return detect_requires_poll_watcher_freebsd(path);
+    }
+
+    #[cfg(not(any(target_os = "linux", target_os = "freebsd")))]
+    {
         let _ = path;
         false
     }
@@ -324,6 +329,52 @@ fn is_wsl_drvfs_path(path: &Path) -> bool {
     let after_mnt = &path[5..];
     after_mnt.starts_with(|c: char| c.is_ascii_alphabetic())
         && (after_mnt.len() == 1 || after_mnt.as_bytes()[1] == b'/')
+}
+
+#[cfg(target_os = "freebsd")]
+fn detect_requires_poll_watcher_freebsd(path: &Path) -> bool {
+    use std::ffi::{CStr, CString};
+    use std::os::unix::ffi::OsStrExt;
+
+    // Check filesystem type via statfs
+    let c_path = match CString::new(path.as_os_str().as_bytes()) {
+        Ok(p) => p,
+        Err(_) => return false,
+    };
+
+    let mut stat: libc::statfs = unsafe { std::mem::zeroed() };
+    if unsafe { libc::statfs(c_path.as_ptr(), &mut stat) } != 0 {
+        return false;
+    }
+
+    // Filesystem type is stored in f_fstypename on FreeBSD
+    let fstype_ptr = stat.f_fstypename.as_ptr();
+    let fstype_res = unsafe { CStr::from_ptr(fstype_ptr) }.to_str();
+
+    if let Ok(fstype) = fstype_res {
+        match fstype {
+            "nfs" | "smbfs" | "fusefs" | "nullfs" => {
+                log::info!(
+                    "Detected {} filesystem at {}, using poll watcher",
+                    fstype,
+                    path.display()
+                );
+                return true;
+            }
+            _ => {}
+        }
+    }
+
+    // Fallback for checking any non-local filesystem flags directly
+    if (stat.f_flags & libc::MNT_LOCAL) == 0 {
+        log::info!(
+            "Detected non-local filesystem at {}, using poll watcher",
+            path.display()
+        );
+        return true;
+    }
+
+    false
 }
 
 async fn poll_path_until_created(
