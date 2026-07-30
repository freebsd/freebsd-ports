--- crates/fs/src/fs.rs.orig	2026-07-29 14:43:24 UTC
+++ crates/fs/src/fs.rs
@@ -460,7 +460,7 @@ impl FileHandle for std::fs::File {
         Ok(new_path)
     }
 
-    #[cfg(target_os = "freebsd")]
+    #[cfg(all(target_os = "freebsd", target_arch = "x86_64"))]
     fn current_path(&self, _: &Arc<dyn Fs>) -> Result<PathBuf> {
         use std::{
             ffi::{CStr, OsStr},
@@ -469,7 +469,10 @@ impl FileHandle for std::fs::File {
 
         let fd = self.as_fd();
         let mut kif = MaybeUninit::<libc::kinfo_file>::uninit();
-        kif.kf_structsize = libc::KINFO_FILE_SIZE;
+        unsafe {
+            std::ptr::write_bytes(kif.as_mut_ptr(), 0, 1);
+            (*kif.as_mut_ptr()).kf_structsize = libc::KINFO_FILE_SIZE;
+        }
 
         let result = unsafe { libc::fcntl(fd.as_raw_fd(), libc::F_KINFO, kif.as_mut_ptr()) };
         anyhow::ensure!(result != -1, "fcntl returned -1");
@@ -481,6 +484,11 @@ impl FileHandle for std::fs::File {
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
@@ -572,7 +580,7 @@ impl RealFs {
     }
 }
 
-#[cfg(any(target_os = "macos", target_os = "linux"))]
+#[cfg(any(target_os = "macos", target_os = "linux", target_os = "freebsd"))]
 fn rename_without_replace(source: &Path, target: &Path) -> io::Result<()> {
     let source = path_to_c_string(source)?;
     let target = path_to_c_string(target)?;
@@ -592,6 +600,27 @@ fn rename_without_replace(source: &Path, target: &Path
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
@@ -619,7 +648,7 @@ fn rename_without_replace(source: &Path, target: &Path
     .map_err(|_| io::Error::last_os_error())
 }
 
-#[cfg(any(target_os = "macos", target_os = "linux"))]
+#[cfg(any(target_os = "macos", target_os = "linux", target_os = "freebsd"))]
 fn path_to_c_string(path: &Path) -> io::Result<CString> {
     CString::new(path.as_os_str().as_bytes()).map_err(|_| {
         io::Error::new(
@@ -723,7 +752,12 @@ impl Fs for RealFs {
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
@@ -756,7 +790,12 @@ impl Fs for RealFs {
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
