--- cargo-crates/pager-0.16.0/src/utils.rs.orig	2022-02-06 16:47:07 UTC
+++ cargo-crates/pager-0.16.0/src/utils.rs
@@ -66,7 +66,7 @@ pub(crate) fn execvpe(cmd: &OsString, envs: &[OsString
     };
     #[cfg(not(target_os = "macos"))]
     unsafe {
-        libc::execvpe(args[0], args.as_ptr(), envs.as_ptr())
+        libc::execve(args[0], args.as_ptr(), envs.as_ptr())
     };
 }
 
