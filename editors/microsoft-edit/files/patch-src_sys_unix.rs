--- src/sys/unix.rs.orig	2025-05-18 18:11:22 UTC
+++ src/sys/unix.rs
@@ -8,9 +8,9 @@ use std::fs::{self, File};
 
 use std::ffi::{CStr, c_int, c_void};
 use std::fs::{self, File};
-use std::mem::{self, MaybeUninit};
+use std::mem::{self, ManuallyDrop, MaybeUninit};
 use std::os::fd::{AsRawFd as _, FromRawFd as _};
-use std::ptr::{self, NonNull, null, null_mut};
+use std::ptr::{self, NonNull, null_mut};
 use std::{thread, time};
 
 use crate::arena::{Arena, ArenaString, scratch_arena};
@@ -195,11 +195,19 @@ pub fn read_stdin(arena: &Arena, mut timeout: time::Du
                 let beg = time::Instant::now();
 
                 let mut pollfd = libc::pollfd { fd: STATE.stdin, events: libc::POLLIN, revents: 0 };
-                let ts = libc::timespec {
-                    tv_sec: timeout.as_secs() as libc::time_t,
-                    tv_nsec: timeout.subsec_nanos() as libc::c_long,
-                };
-                let ret = libc::ppoll(&mut pollfd, 1, &ts, null());
+                let ret;
+                #[cfg(target_os = "linux")]
+                {
+                    let ts = libc::timespec {
+                        tv_sec: timeout.as_secs() as libc::time_t,
+                        tv_nsec: timeout.subsec_nanos() as libc::c_long,
+                    };
+                    ret = libc::ppoll(&mut pollfd, 1, &ts, ptr::null());
+                }
+                #[cfg(not(target_os = "linux"))]
+                {
+                    ret = libc::poll(&mut pollfd, 1, timeout.as_millis() as libc::c_int);
+                }
                 if ret < 0 {
                     return None; // Error? Let's assume it's an EOF.
                 }
@@ -225,7 +233,7 @@ pub fn read_stdin(arena: &Arena, mut timeout: time::Du
                 return None; // EOF
             }
             if ret < 0 {
-                match *libc::__errno_location() {
+                match errno() {
                     libc::EINTR if STATE.inject_resize => break,
                     libc::EAGAIN if timeout == time::Duration::ZERO => break,
                     libc::EINTR | libc::EAGAIN => {}
@@ -304,7 +312,7 @@ pub fn write_stdout(text: &str) {
             continue;
         }
 
-        let err = unsafe { *libc::__errno_location() };
+        let err = errno();
         if err != libc::EINTR {
             return;
         }
@@ -407,7 +415,7 @@ unsafe fn load_library(name: &CStr) -> apperr::Result<
 unsafe fn load_library(name: &CStr) -> apperr::Result<NonNull<c_void>> {
     unsafe {
         NonNull::new(libc::dlopen(name.as_ptr(), libc::RTLD_LAZY))
-            .ok_or_else(|| errno_to_apperr(libc::ELIBACC))
+            .ok_or_else(|| errno_to_apperr(libc::ENOENT))
     }
 }
 
@@ -423,7 +431,7 @@ pub unsafe fn get_proc_address<T>(handle: NonNull<c_vo
     unsafe {
         let sym = libc::dlsym(handle.as_ptr(), name.as_ptr());
         if sym.is_null() {
-            Err(errno_to_apperr(libc::ELIBACC))
+            Err(errno_to_apperr(libc::ENOENT))
         } else {
             Ok(mem::transmute_copy(&sym))
         }
@@ -538,6 +546,14 @@ pub fn preferred_languages(arena: &Arena) -> Vec<Arena
 }
 
 #[inline]
+fn errno() -> i32 {
+    // Under `-O -Copt-level=s` the 1.87 compiler fails to fully inline and
+    // remove the raw_os_error() call. This leaves us with the drop() call.
+    // ManuallyDrop fixes that and results in a direct `std::sys::os::errno` call.
+    ManuallyDrop::new(std::io::Error::last_os_error()).raw_os_error().unwrap_or(0)
+}
+
+#[inline]
 pub(crate) fn io_error_to_apperr(err: std::io::Error) -> apperr::Error {
     errno_to_apperr(err.raw_os_error().unwrap_or(0))
 }
@@ -565,5 +581,5 @@ fn check_int_return(ret: libc::c_int) -> apperr::Resul
 }
 
 fn check_int_return(ret: libc::c_int) -> apperr::Result<libc::c_int> {
-    if ret < 0 { Err(errno_to_apperr(unsafe { *libc::__errno_location() })) } else { Ok(ret) }
+    if ret < 0 { Err(errno_to_apperr(errno())) } else { Ok(ret) }
 }
