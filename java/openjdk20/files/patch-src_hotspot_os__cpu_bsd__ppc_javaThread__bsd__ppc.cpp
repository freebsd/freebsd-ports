--- src/hotspot/os_cpu/bsd_ppc/javaThread_bsd_ppc.cpp.orig	2023-10-02 13:02:10 UTC
+++ src/hotspot/os_cpu/bsd_ppc/javaThread_bsd_ppc.cpp
@@ -58,14 +58,14 @@ bool JavaThread::pd_get_top_frame_for_profiling(frame*
   // if we were running Java code when SIGPROF came in.
   if (isInJava) {
     ucontext_t* uc = (ucontext_t*) ucontext;
-    address pc = (address)uc->uc_mcontext.regs->nip;
+    address pc = (address)uc->uc_mcontext.mc_srr0;
 
     if (pc == NULL) {
       // ucontext wasn't useful
       return false;
     }
 
-    frame ret_frame((intptr_t*)uc->uc_mcontext.regs->gpr[1/*REG_SP*/], pc);
+    frame ret_frame((intptr_t*)uc->uc_mcontext.mc_gpr[1/*REG_SP*/], pc);
 
     if (ret_frame.fp() == NULL) {
       // The found frame does not have a valid frame pointer.
@@ -84,7 +84,7 @@ bool JavaThread::pd_get_top_frame_for_profiling(frame*
       if (!Method::is_valid_method(m)) return false;
       if (!Metaspace::contains(m->constMethod())) return false;
 
-      uint64_t reg_bcp = uc->uc_mcontext.regs->gpr[14/*R14_bcp*/];
+      uint64_t reg_bcp = uc->uc_mcontext.mc_gpr[14/*R14_bcp*/];
       uint64_t istate_bcp = istate->bcp;
       uint64_t code_start = (uint64_t)(m->code_base());
       uint64_t code_end = (uint64_t)(m->code_base() + m->code_size());
