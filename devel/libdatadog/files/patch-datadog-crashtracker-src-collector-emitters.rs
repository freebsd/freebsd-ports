--- datadog-crashtracker/src/collector/emitters.rs.orig	2025-11-03 12:41:37 UTC
+++ datadog-crashtracker/src/collector/emitters.rs
@@ -198,7 +198,7 @@ fn emit_proc_self_maps(w: &mut impl Write) -> Result<(
     Ok(())
 }
 
-#[cfg(target_os = "linux")]
+#[cfg(any(target_os = "freebsd", target_os = "linux"))]
 fn emit_ucontext(w: &mut impl Write, ucontext: *const ucontext_t) -> Result<(), EmitterError> {
     if ucontext.is_null() {
         return Err(EmitterError::NullUcontext);
@@ -325,6 +325,11 @@ fn extract_ip(ucontext: *const ucontext_t) -> usize {
         return (*(*ucontext).uc_mcontext).__ss.__rip as usize;
         #[cfg(all(target_os = "macos", target_arch = "aarch64"))]
         return (*(*ucontext).uc_mcontext).__ss.__pc as usize;
+
+        #[cfg(all(target_os = "freebsd", target_arch = "x86_64"))]
+        return (*ucontext).uc_mcontext.mc_rip as usize;
+        #[cfg(all(target_os = "freebsd", target_arch = "aarch64"))]
+        return (*ucontext).uc_mcontext.mc_gpregs.gp_pc;
 
         #[cfg(all(target_os = "linux", target_arch = "x86_64"))]
         return (*ucontext).uc_mcontext.gregs[libc::REG_RIP as usize] as usize;
