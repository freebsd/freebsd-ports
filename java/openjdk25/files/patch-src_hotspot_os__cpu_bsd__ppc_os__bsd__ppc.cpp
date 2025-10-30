--- src/hotspot/os_cpu/bsd_ppc/os_bsd_ppc.cpp.orig	2025-10-30 14:38:45 UTC
+++ src/hotspot/os_cpu/bsd_ppc/os_bsd_ppc.cpp
@@ -179,7 +179,7 @@ intptr_t* os::fetch_bcp_from_context(const void* ucVoi
   assert(ucVoid != nullptr, "invariant");
   const ucontext_t* uc = (const ucontext_t*)ucVoid;
   assert(os::Posix::ucontext_is_interpreter(uc), "invariant");
-  return reinterpret_cast<intptr_t*>(uc->uc_mcontext.regs->gpr[14]); // R14_bcp
+  return reinterpret_cast<intptr_t*>(uc->uc_mcontext.mc_gpr[14]); // R14_bcp
 }
 
 frame os::get_sender_for_C_frame(frame* fr) {
