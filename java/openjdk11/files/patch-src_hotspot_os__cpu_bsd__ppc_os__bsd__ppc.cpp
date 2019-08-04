--- src/hotspot/os_cpu/bsd_ppc/os_bsd_ppc.cpp.orig
+++ src/hotspot/os_cpu/bsd_ppc/os_bsd_ppc.cpp
@@ -133,7 +133,7 @@
 }
 
 static unsigned long ucontext_get_trap(const ucontext_t * uc) {
-  return uc->uc_mcontext.regs->trap;
+  return uc->uc_mcontext.mc_exc;
 }
 
 ExtendedPC os::fetch_frame_from_context(const void* ucVoid,
