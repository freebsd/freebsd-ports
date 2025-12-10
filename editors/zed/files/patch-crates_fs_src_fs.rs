--- crates/fs/src/fs.rs.orig	2025-12-03 16:43:47 UTC
+++ crates/fs/src/fs.rs
@@ -358,7 +358,7 @@ impl FileHandle for std::fs::File {
         Ok(new_path)
     }
 
-    #[cfg(target_os = "freebsd")]
+    #[cfg(all(target_os = "freebsd", target_arch = "x86_64"))]
     fn current_path(&self, _: &Arc<dyn Fs>) -> Result<PathBuf> {
         use std::{
             ffi::{CStr, OsStr},
@@ -367,7 +367,10 @@ impl FileHandle for std::fs::File {
 
         let fd = self.as_fd();
         let mut kif = MaybeUninit::<libc::kinfo_file>::uninit();
-        kif.kf_structsize = libc::KINFO_FILE_SIZE;
+        unsafe {
+            std::ptr::write_bytes(kif.as_mut_ptr(), 0, 1);
+            (*kif.as_mut_ptr()).kf_structsize = libc::KINFO_FILE_SIZE;
+        }
 
         let result = unsafe { libc::fcntl(fd.as_raw_fd(), libc::F_KINFO, kif.as_mut_ptr()) };
         if result == -1 {
@@ -378,6 +381,11 @@ impl FileHandle for std::fs::File {
         let c_str = unsafe { CStr::from_ptr(kif.assume_init().kf_path.as_ptr()) };
         let path = PathBuf::from(OsStr::from_bytes(c_str.to_bytes()));
         Ok(path)
+    }
+
+    #[cfg(all(target_os = "freebsd", not(target_arch = "x86_64")))]
+    fn current_path(&self, _: &Arc<dyn Fs>) -> Result<PathBuf> {
+        anyhow::bail!("unimplemented")
     }
 
     #[cfg(target_os = "windows")]
