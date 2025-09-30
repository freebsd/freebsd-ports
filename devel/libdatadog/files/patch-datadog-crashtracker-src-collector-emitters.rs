--- datadog-crashtracker/src/collector/emitters.rs.orig	2025-02-11 17:46:31 UTC
+++ datadog-crashtracker/src/collector/emitters.rs
@@ -178,7 +178,7 @@ fn emit_proc_self_maps(w: &mut impl Write) -> Result<(
     Ok(())
 }
 
-#[cfg(target_os = "linux")]
+#[cfg(any(target_os = "freebsd", target_os = "linux"))]
 fn emit_ucontext(w: &mut impl Write, ucontext: *const ucontext_t) -> Result<(), EmitterError> {
     if ucontext.is_null() {
         return Err(EmitterError::NullUcontext);
@@ -305,6 +305,11 @@ fn extract_rsp(ucontext: *const ucontext_t) -> usize {
         return (*(*ucontext).uc_mcontext).__ss.__rsp as usize;
         #[cfg(all(target_os = "macos", target_arch = "aarch64"))]
         return (*(*ucontext).uc_mcontext).__ss.__sp as usize;
+
+        #[cfg(all(target_os = "freebsd", target_arch = "x86_64"))]
+        return (*ucontext).uc_mcontext.mc_rsp as usize;
+        #[cfg(all(target_os = "freebsd", target_arch = "aarch64"))]
+        return (*ucontext).uc_mcontext.mc_gpregs.gp_sp;
 
         #[cfg(all(target_os = "linux", target_arch = "x86_64"))]
         return (*ucontext).uc_mcontext.gregs[libc::REG_RSP as usize] as usize;
