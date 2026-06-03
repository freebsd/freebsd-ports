--- crates/fs/src/fs.rs.orig	2026-03-24 22:04:08 UTC
+++ crates/fs/src/fs.rs
@@ -374,7 +374,7 @@ impl FileHandle for std::fs::File {
 
         let fd = self.as_fd();
         let mut kif = MaybeUninit::<libc::kinfo_file>::uninit();
-        kif.kf_structsize = libc::KINFO_FILE_SIZE;
+        unsafe { (*kif.as_mut_ptr()).kf_structsize = libc::KINFO_FILE_SIZE; }
 
         let result = unsafe { libc::fcntl(fd.as_raw_fd(), libc::F_KINFO, kif.as_mut_ptr()) };
         anyhow::ensure!(result != -1, "fcntl returned -1");
