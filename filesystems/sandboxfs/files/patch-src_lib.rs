--- src/lib.rs.orig	2020-04-20 18:46:46 UTC
+++ src/lib.rs
@@ -463,10 +463,10 @@ impl SandboxFS {
                 #[cfg(target_os = "linux")]
                 let code = Errno::ENODATA;
 
-                #[cfg(target_os = "macos")]
+                #[cfg(any(target_os = "dragonfly", target_os = "freebsd", target_os = "macos"))]
                 let code = Errno::ENOATTR;
 
-                #[cfg(not(any(target_os = "linux", target_os = "macos")))]
+                #[cfg(not(any(target_os = "dragonfly", target_os = "freebsd", target_os = "linux", target_os = "macos")))]
                 compile_error!("Don't know what error to return on a missing getxattr");
 
                 Err(KernelError::from_errno(code))
