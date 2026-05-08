--- crates/fs/src/fs.rs.orig	2026-05-06 20:35:33 UTC
+++ crates/fs/src/fs.rs
@@ -96,8 +96,14 @@ pub fn requires_poll_watcher(path: &Path) -> bool {
         return detect_requires_poll_watcher_linux(&path);
     }
 
-    #[cfg(not(target_os = "linux"))]
+    #[cfg(target_os = "freebsd")]
     {
+        let path = effective_watch_path(path);
+        return detect_requires_poll_watcher_freebsd(&path);
+    }
+
+    #[cfg(not(any(target_os = "linux", target_os = "freebsd")))]
+    {
         let _ = path;
         false
     }
@@ -198,6 +204,52 @@ fn is_wsl_drvfs_path(path: &Path) -> bool {
         && (after_mnt.len() == 1 || after_mnt.as_bytes()[1] == b'/')
 }
 
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
+}
+
 #[derive(Copy, Clone, PartialEq, Eq, PartialOrd, Ord, Debug)]
 pub enum PathEventKind {
     Removed,
@@ -568,7 +620,7 @@ impl FileHandle for std::fs::File {
         Ok(new_path)
     }
 
-    #[cfg(target_os = "freebsd")]
+    #[cfg(all(target_os = "freebsd", target_arch = "x86_64"))]
     fn current_path(&self, _: &Arc<dyn Fs>) -> Result<PathBuf> {
         use std::{
             ffi::{CStr, OsStr},
@@ -577,7 +629,10 @@ impl FileHandle for std::fs::File {
 
         let fd = self.as_fd();
         let mut kif = MaybeUninit::<libc::kinfo_file>::uninit();
-        kif.kf_structsize = libc::KINFO_FILE_SIZE;
+        unsafe {
+            std::ptr::write_bytes(kif.as_mut_ptr(), 0, 1);
+            (*kif.as_mut_ptr()).kf_structsize = libc::KINFO_FILE_SIZE;
+        }
 
         let result = unsafe { libc::fcntl(fd.as_raw_fd(), libc::F_KINFO, kif.as_mut_ptr()) };
         anyhow::ensure!(result != -1, "fcntl returned -1");
@@ -589,6 +644,11 @@ impl FileHandle for std::fs::File {
         Ok(path)
     }
 
+    #[cfg(all(target_os = "freebsd", not(target_arch = "x86_64")))]
+    fn current_path(&self, _: &Arc<dyn Fs>) -> Result<PathBuf> {
+        anyhow::bail!("unimplemented")
+    }
+
     #[cfg(target_os = "windows")]
     fn current_path(&self, _: &Arc<dyn Fs>) -> Result<PathBuf> {
         use std::ffi::OsString;
@@ -679,7 +739,7 @@ impl RealFs {
     }
 }
 
-#[cfg(any(target_os = "macos", target_os = "linux"))]
+#[cfg(any(target_os = "macos", target_os = "linux", target_os = "freebsd"))]
 fn rename_without_replace(source: &Path, target: &Path) -> io::Result<()> {
     let source = path_to_c_string(source)?;
     let target = path_to_c_string(target)?;
@@ -699,6 +759,27 @@ fn rename_without_replace(source: &Path, target: &Path
         )
     };
 
+    #[cfg(target_os = "freebsd")]
+    let result = unsafe {
+        let ret = libc::link(source.as_ptr(), target.as_ptr());
+        if ret == 0 {
+            libc::unlink(source.as_ptr())
+        } else {
+            let err = io::Error::last_os_error();
+            if err.raw_os_error() == Some(libc::EPERM) || err.raw_os_error() == Some(libc::EMLINK) {
+                let mut st = std::mem::zeroed();
+                if libc::lstat(target.as_ptr(), &mut st) == 0 {
+                    *libc::__error() = libc::EEXIST;
+                    -1
+                } else {
+                    libc::rename(source.as_ptr(), target.as_ptr())
+                }
+            } else {
+                -1
+            }
+        }
+    };
+
     if result == 0 {
         Ok(())
     } else {
@@ -726,7 +807,7 @@ fn rename_without_replace(source: &Path, target: &Path
     .map_err(|_| io::Error::last_os_error())
 }
 
-#[cfg(any(target_os = "macos", target_os = "linux"))]
+#[cfg(any(target_os = "macos", target_os = "linux", target_os = "freebsd"))]
 fn path_to_c_string(path: &Path) -> io::Result<CString> {
     CString::new(path.as_os_str().as_bytes()).map_err(|_| {
         io::Error::new(
@@ -830,7 +911,12 @@ impl Fs for RealFs {
         }
 
         let use_metadata_fallback = {
-            #[cfg(any(target_os = "macos", target_os = "linux", target_os = "windows"))]
+            #[cfg(any(
+                target_os = "macos",
+                target_os = "linux",
+                target_os = "windows",
+                target_os = "freebsd"
+            ))]
             {
                 let source = source.to_path_buf();
                 let target = target.to_path_buf();
@@ -863,7 +949,12 @@ impl Fs for RealFs {
                 }
             }
 
-            #[cfg(not(any(target_os = "macos", target_os = "linux", target_os = "windows")))]
+            #[cfg(not(any(
+                target_os = "macos",
+                target_os = "linux",
+                target_os = "windows",
+                target_os = "freebsd"
+            )))]
             {
                 // For platforms which do not have an atomic no-overwrite rename yet.
                 true
