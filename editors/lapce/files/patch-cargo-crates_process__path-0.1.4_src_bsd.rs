--- cargo-crates/process_path-0.1.4/src/bsd.rs.orig	2022-10-06 14:01:42 UTC
+++ cargo-crates/process_path-0.1.4/src/bsd.rs
@@ -35,7 +35,7 @@ pub fn get_executable_path() -> Option<PathBuf> {
     // FreeBSD without procfs
     if result == 0 {
         // Convert the string allocated on the stack to a Rust string.
-        let len = unsafe { strlen(buf.as_ptr() as *const i8) };
+        let len = unsafe { strlen(buf.as_ptr() as *const libc::c_char) };
         unsafe { buf.set_len(len) };
         match String::from_utf8(buf).ok() {
             Some(path) => {
