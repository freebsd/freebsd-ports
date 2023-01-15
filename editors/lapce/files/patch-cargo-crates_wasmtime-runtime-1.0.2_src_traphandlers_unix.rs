--- cargo-crates/wasmtime-runtime-1.0.2/src/traphandlers/unix.rs.orig	2023-01-13 13:01:32 UTC
+++ cargo-crates/wasmtime-runtime-1.0.2/src/traphandlers/unix.rs
@@ -228,6 +228,12 @@ unsafe fn get_pc_and_fp(cx: *mut libc::c_void, _signum
                 cx.uc_mcontext.mc_rip as *const u8,
                 cx.uc_mcontext.mc_rbp as usize,
             )
+        } else if #[cfg(all(target_os = "freebsd", target_arch = "aarch64"))] {
+            let cx = &*(cx as *const libc::mcontext_t);
+            (
+                cx.mc_gpregs.gp_elr as *const u8,
+                cx.mc_gpregs.gp_x[29] as usize,
+            )
         } else {
             compile_error!("unsupported platform");
         }
