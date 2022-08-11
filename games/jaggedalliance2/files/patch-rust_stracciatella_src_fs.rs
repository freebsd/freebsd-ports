--- rust/stracciatella/src/fs.rs.orig	2022-05-02 13:31:34 UTC
+++ rust/stracciatella/src/fs.rs
@@ -59,7 +59,7 @@ pub fn remove_file<P: AsRef<Path>>(path: P) -> Result<
 pub fn rename<P: AsRef<Path>>(from: P, to: P) -> Result<(), io::Error> {
     match std::fs::rename(&from, &to) {
         Ok(()) => Ok(()),
-        #[cfg(target_os = "linux")]
+        #[cfg(target_family = "unix")]
         Err(e) if e.raw_os_error() == Some(libc::EXDEV) => {
             std::fs::copy(&from, &to).and_then(|_| remove_file(&from))
         }
