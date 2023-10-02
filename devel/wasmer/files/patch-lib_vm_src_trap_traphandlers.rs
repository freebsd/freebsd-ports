--- lib/vm/src/trap/traphandlers.rs.orig	2023-04-07 07:18:13 UTC
+++ lib/vm/src/trap/traphandlers.rs
@@ -52,7 +52,21 @@ struct ucontext_t {
     uc_mcontext: libc::mcontext_t,
 }
 
-#[cfg(all(unix, not(all(target_arch = "aarch64", target_os = "macos"))))]
+// Current definition of `ucontext_t` in the `libc` crate is not present
+// on aarch64-unknown-freebsd so it's defined here.
+#[repr(C)]
+#[cfg(all(target_arch = "aarch64", target_os = "freebsd"))]
+#[allow(non_camel_case_types)]
+struct ucontext_t {
+    uc_sigmask: libc::sigset_t,
+    uc_mcontext: libc::mcontext_t,
+    uc_link: *mut ucontext_t,
+    uc_stack: libc::stack_t,
+    uc_flags: libc::c_int,
+    spare: [libc::c_int; 4], 
+}
+
+#[cfg(all(unix, not(all(target_arch = "aarch64", target_os = "macos")), not(all(target_arch="aarch64", target_os="freebsd"))))]
 use libc::ucontext_t;
 
 /// Default stack size is 1MB.
@@ -434,7 +448,8 @@ cfg_if::cfg_if! {
                     (*context.uc_mcontext).__ss.__fp = x29;
                     (*context.uc_mcontext).__ss.__lr = lr;
                 } else if #[cfg(all(target_os = "freebsd", target_arch = "aarch64"))] {
-                    context.uc_mcontext.mc_gpregs.gp_pc = pc as libc::register_t;
+                    let TrapHandlerRegs { pc, sp, x0, x1, x29, lr } = regs;
+                    context.uc_mcontext.mc_gpregs.gp_elr = pc as libc::register_t;
                     context.uc_mcontext.mc_gpregs.gp_sp = sp as libc::register_t;
                     context.uc_mcontext.mc_gpregs.gp_x[0] = x0 as libc::register_t;
                     context.uc_mcontext.mc_gpregs.gp_x[1] = x1 as libc::register_t;
