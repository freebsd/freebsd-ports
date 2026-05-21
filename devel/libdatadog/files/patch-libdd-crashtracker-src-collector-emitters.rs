--- libdd-crashtracker/src/collector/emitters.rs.orig	2025-11-24 20:38:29.000000000 +0100
+++ libdd-crashtracker/src/collector/emitters.rs	2026-05-21 11:19:15.044623000 +0200
@@ -207,7 +207,7 @@
     Ok(())
 }
 
-#[cfg(target_os = "linux")]
+#[cfg(any(target_os = "freebsd", target_os = "linux"))]
 fn emit_ucontext(w: &mut impl Write, ucontext: *const ucontext_t) -> Result<(), EmitterError> {
     if ucontext.is_null() {
         return Err(EmitterError::NullUcontext);
@@ -380,6 +380,13 @@
         #[cfg(all(target_os = "macos", target_arch = "aarch64"))]
         return (*(*ucontext).uc_mcontext).__ss.__pc as usize;
 
+        #[cfg(all(target_os = "freebsd", target_arch = "x86_64"))]
+        return (*ucontext).uc_mcontext.mc_rip as usize;
+        #[cfg(all(target_os = "freebsd", target_arch = "aarch64"))]
+        return (*ucontext).uc_mcontext.mc_gpregs.gp_pc;
+        #[cfg(all(target_os = "freebsd", target_arch = "powerpc64"))]
+        return (*ucontext).uc_mcontext.mc_frame[36] as usize;
+
         #[cfg(all(target_os = "linux", target_arch = "x86_64"))]
         return (*ucontext).uc_mcontext.gregs[libc::REG_RIP as usize] as usize;
         #[cfg(all(target_os = "linux", target_arch = "aarch64"))]
