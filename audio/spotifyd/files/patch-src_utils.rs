--- src/utils.rs.orig	2021-02-09 22:43:15 UTC
+++ src/utils.rs
@@ -3,7 +3,7 @@
 #[cfg(target_os = "macos")]
 use whoami;
 
-#[cfg(target_os = "linux")]
+#[cfg(any(target_os = "freebsd", target_os = "linux"))]
 fn get_shell_ffi() -> Option<String> {
     use libc::{geteuid, getpwuid_r};
     use std::{ffi::CStr, mem, ptr};
