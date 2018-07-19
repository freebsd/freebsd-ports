--- src/libstd/sys/unix/stack_overflow.rs.orig	2018-06-19 04:35:53 UTC
+++ src/libstd/sys/unix/stack_overflow.rs
@@ -148,18 +148,20 @@ mod imp {
         stackp
     }
 
-    #[cfg(any(target_os = "linux",
-              target_os = "macos",
-              target_os = "bitrig",
-              target_os = "netbsd",
-              target_os = "openbsd",
-              target_os = "solaris"))]
+    #[cfg(any(any(target_os = "linux",
+                  target_os = "macos",
+                  target_os = "bitrig",
+                  target_os = "netbsd",
+                  target_os = "openbsd",
+                  target_os = "solaris"),
+              all(target_os = "freebsd", target_arch = "aarch64")))]
     unsafe fn get_stack() -> libc::stack_t {
         libc::stack_t { ss_sp: get_stackp(), ss_flags: 0, ss_size: SIGSTKSZ }
     }
 
-    #[cfg(any(target_os = "freebsd",
-              target_os = "dragonfly"))]
+    #[cfg(all(any(target_os = "freebsd",
+                  target_os = "dragonfly"),
+              not(target_arch = "aarch64")))]
     unsafe fn get_stack() -> libc::stack_t {
         libc::stack_t { ss_sp: get_stackp() as *mut i8, ss_flags: 0, ss_size: SIGSTKSZ }
     }
