-- Add support for FreeBSD ARM64 (aarch64) in wasmtime signal handling
-- The extract function already supported FreeBSD aarch64, but the store function
-- was missing support. This causes a compile_error on ARM64 builds.
-- Fixes: "error: unsupported platform" on aarch64-unknown-freebsd target

--- cargo-crates/wasmtime-42.0.1/src/runtime/vm/sys/unix/signals.rs.orig	2026-04-29 14:21:05 UTC
+++ cargo-crates/wasmtime-42.0.1/src/runtime/vm/sys/unix/signals.rs
@@ -383,6 +383,13 @@ unsafe fn store_handler_in_ucontext(cx: *mut libc::c_v
             cx.uc_mcontext.mc_rsp = handler.sp as _;
             cx.uc_mcontext.mc_rax = 0;
             cx.uc_mcontext.mc_rdx = 0;
+        } else if #[cfg(all(target_os = "freebsd", target_arch = "aarch64"))] {
+            let cx = unsafe { cx.cast::<libc::mcontext_t>().as_mut().unwrap() };
+            cx.mc_gpregs.gp_elr = handler.pc as _;
+            cx.mc_gpregs.gp_sp = handler.sp as _;
+            cx.mc_gpregs.gp_x[29] = handler.fp as _;
+            cx.mc_gpregs.gp_x[0] = 0;
+            cx.mc_gpregs.gp_x[1] = 0;
         } else if #[cfg(all(target_os = "openbsd", target_arch = "x86_64"))] {
             let cx = unsafe { cx.cast::<libc::ucontext_t>().as_mut().unwrap() };
             cx.sc_rip = handler.pc as _;
