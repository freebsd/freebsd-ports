--- vendor/backtrace/src/backtrace/libunwind.rs.orig	2019-04-08 14:18:22 UTC
+++ vendor/backtrace/src/backtrace/libunwind.rs
@@ -113,12 +113,14 @@ mod uw {
 
         // available since GCC 4.2.0, should be fine for our purpose
         #[cfg(all(not(all(target_os = "android", target_arch = "arm")),
+                  not(all(target_os = "freebsd", target_arch = "arm")),
                   not(all(target_os = "linux", target_arch = "arm"))))]
         pub fn _Unwind_GetIPInfo(ctx: *mut _Unwind_Context,
                                  ip_before_insn: *mut c_int)
                     -> libc::uintptr_t;
 
         #[cfg(all(not(target_os = "android"),
+                  not(all(target_os = "freebsd", target_arch = "arm")),
                   not(all(target_os = "linux", target_arch = "arm"))))]
         pub fn _Unwind_FindEnclosingFunction(pc: *mut c_void)
             -> *mut c_void;
@@ -128,6 +130,7 @@ mod uw {
     // expansion of the macro. This is all copy/pasted directly from the
     // header file with the definition of _Unwind_GetIP.
     #[cfg(any(all(target_os = "android", target_arch = "arm"),
+              all(target_os = "freebsd", target_arch = "arm"),
               all(target_os = "linux", target_arch = "arm")))]
     pub unsafe fn _Unwind_GetIP(ctx: *mut _Unwind_Context) -> libc::uintptr_t {
         #[repr(C)]
@@ -175,6 +178,7 @@ mod uw {
     // This function doesn't exist on Android or ARM/Linux, so make it same
     // to _Unwind_GetIP
     #[cfg(any(all(target_os = "android", target_arch = "arm"),
+              all(target_os = "freebsd", target_arch = "arm"),
               all(target_os = "linux", target_arch = "arm")))]
     pub unsafe fn _Unwind_GetIPInfo(ctx: *mut _Unwind_Context,
                                     ip_before_insn: *mut c_int)
@@ -187,6 +191,7 @@ mod uw {
     // This function also doesn't exist on Android or ARM/Linux, so make it
     // a no-op
     #[cfg(any(target_os = "android",
+              all(target_os = "freebsd", target_arch = "arm"),
               all(target_os = "linux", target_arch = "arm")))]
     pub unsafe fn _Unwind_FindEnclosingFunction(pc: *mut c_void)
         -> *mut c_void
