--- cargo-crates/interprocess-1.1.1/src/os/unix/imports.rs.orig	2022-09-05 13:24:51 UTC
+++ cargo-crates/interprocess-1.1.1/src/os/unix/imports.rs
@@ -46,7 +46,7 @@ cfg_if! {
             sockaddr_un,
             msghdr, cmsghdr,
         };
-        #[cfg(not(any(target_os = "macos", target_os = "ios")))]
+        #[cfg(not(any(target_os = "freebsd", target_os = "macos", target_os = "ios")))]
         pub(super) use libc::{
             SIGPOLL,
             SO_PASSCRED,
@@ -56,9 +56,9 @@ cfg_if! {
             ucred,
         };
 
-        #[cfg(any(target_os = "macos", target_os = "ios"))]
+        #[cfg(any(target_os = "freebsd", target_os = "macos", target_os = "ios"))]
         pub(super) const SIGPOLL: i32 = 999;
-        #[cfg(any(target_os = "macos", target_os = "ios"))]
+        #[cfg(any(target_os = "freebsd", target_os = "macos", target_os = "ios"))]
         #[doc(hidden)]
         pub struct ucred {}
 
