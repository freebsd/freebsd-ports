error[E0308]: mismatched types
    --> compiler/rustc_driver_impl/src/signal_handler.rs:43:63
     |
43   |        let depth = libc::backtrace(STACK_TRACE.as_mut_ptr(), MAX_FRAMES as i32);
     |                    ---------------                           ^^^^^^^^^^^^^^^^^ expected `usize`, found `i32`
     |                    |
     |                    arguments to this function are incorrect
     |
note: function defined here
    --> /wrkdirs/usr/ports/lang/rust-bootstrap/work-armv7/rustc-1.78.0-src/vendor/libc/src/unix/bsd/freebsdlike/mod.rs:1861:12
     |
1861 |     pub fn backtrace(addrlist: *mut *mut ::c_void, len: ::size_t) -> ::size_t;
     |            ^^^^^^^^^
help: you can convert an `i32` to a `usize` and panic if the converted value doesn't fit
     |
43   |         let depth = libc::backtrace(STACK_TRACE.as_mut_ptr(), (MAX_FRAMES as i32).try_into().unwrap());

--- compiler/rustc_driver_impl/src/signal_handler.rs.orig	2024-05-06 16:00:17 UTC
+++ compiler/rustc_driver_impl/src/signal_handler.rs
@@ -46,7 +46,7 @@ unsafe extern "C" fn print_stack_trace(_: libc::c_int)
         // in incredibly undesirable and unexpected ways due to e.g. the allocator deadlocking
         static mut STACK_TRACE: [*mut libc::c_void; MAX_FRAMES] = [ptr::null_mut(); MAX_FRAMES];
         // Collect return addresses
-        let depth = libc::backtrace(&raw mut STACK_TRACE as _, MAX_FRAMES as i32);
+        let depth = libc::backtrace(&raw mut STACK_TRACE as _, (MAX_FRAMES as i32).try_into().unwrap());
         if depth == 0 {
             return;
         }
