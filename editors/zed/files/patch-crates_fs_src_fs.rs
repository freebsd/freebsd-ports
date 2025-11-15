--- crates/fs/src/fs.rs.orig	2025-11-15 04:52:04 UTC
+++ crates/fs/src/fs.rs
@@ -309,7 +309,10 @@ impl FileHandle for std::fs::File {
 
         let fd = self.as_fd();
         let mut kif = MaybeUninit::<libc::kinfo_file>::uninit();
-        kif.kf_structsize = libc::KINFO_FILE_SIZE;
+        unsafe {
+            std::ptr::write_bytes(kif.as_mut_ptr(), 0, 1);
+            (*kif.as_mut_ptr()).kf_structsize = libc::KINFO_FILE_SIZE;
+        }
 
         let result = unsafe { libc::fcntl(fd.as_raw_fd(), libc::F_KINFO, kif.as_mut_ptr()) };
         if result == -1 {
