--- cargo-crates/wasmtime-41.0.4/src/runtime/vm/sys/unix/signals.rs.orig	2026-07-01 09:28:45 UTC
+++ cargo-crates/wasmtime-41.0.4/src/runtime/vm/sys/unix/signals.rs
@@ -397,6 +397,13 @@ unsafe fn store_handler_in_ucontext(cx: *mut libc::c_v
             cx.uc_mcontext.__gregs[libc::REG_SP] = handler.sp as _;
             cx.uc_mcontext.__gregs[libc::REG_A0] = 0;
             cx.uc_mcontext.__gregs[libc::REG_A0 + 1] = 0;
+        } else if #[cfg(all(target_os = "freebsd", target_arch = "aarch64"))] {
+            let cx = unsafe { cx.cast::<libc::ucontext_t>().as_mut().unwrap() };
+            cx.uc_mcontext.mc_gpregs.gp_elr = handler.pc as _;
+            cx.uc_mcontext.mc_gpregs.gp_sp = handler.sp as _;
+            cx.uc_mcontext.mc_gpregs.gp_x[29] = handler.fp as _;
+            cx.uc_mcontext.mc_gpregs.gp_x[0] = 0;
+            cx.uc_mcontext.mc_gpregs.gp_x[1] = 0;
         } else {
             compile_error!("unsupported platform");
             panic!();
