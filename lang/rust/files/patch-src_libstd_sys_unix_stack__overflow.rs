--- src/libstd/sys/unix/stack_overflow.rs.orig	2019-04-08 12:42:31 UTC
+++ src/libstd/sys/unix/stack_overflow.rs
@@ -141,6 +141,7 @@ mod imp {
     #[cfg(any(target_os = "linux",
               target_os = "macos",
               target_os = "bitrig",
+              target_os = "freebsd",
               target_os = "netbsd",
               target_os = "openbsd",
               target_os = "solaris"))]
@@ -148,8 +149,7 @@ mod imp {
         libc::stack_t { ss_sp: get_stackp(), ss_flags: 0, ss_size: SIGSTKSZ }
     }
 
-    #[cfg(any(target_os = "freebsd",
-              target_os = "dragonfly"))]
+    #[cfg(target_os = "dragonfly")]
     unsafe fn get_stack() -> libc::stack_t {
         libc::stack_t { ss_sp: get_stackp() as *mut i8, ss_flags: 0, ss_size: SIGSTKSZ }
     }
