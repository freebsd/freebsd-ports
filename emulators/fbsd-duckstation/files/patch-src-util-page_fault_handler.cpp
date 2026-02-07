Fix build on arm64

--- src/util/page_fault_handler.cpp.orig	2024-06-14 05:59:32 UTC
+++ src/util/page_fault_handler.cpp
@@ -188,8 +188,8 @@ void PageFaultHandler::SignalHandler(int sig, siginfo_
   void* const exception_pc = reinterpret_cast<void*>(static_cast<ucontext_t*>(ctx)->uc_mcontext.mc_rip);
   const bool is_write = (static_cast<ucontext_t*>(ctx)->uc_mcontext.mc_err & 2) != 0;
 #elif defined(CPU_ARCH_ARM64)
-  void* const exception_address = reinterpret_cast<void*>(static_cast<ucontext_t*>(ctx)->uc_mcontext->__es.__far);
-  void* const exception_pc = reinterpret_cast<void*>(static_cast<ucontext_t*>(ctx)->uc_mcontext->__ss.__pc);
+  void* const exception_address = reinterpret_cast<void*>(info->si_addr);
+  void* const exception_pc = reinterpret_cast<void*>(static_cast<ucontext_t*>(ctx)->uc_mcontext.mc_gpregs.gp_elr);
   const bool is_write = IsStoreInstruction(exception_pc);
 #else
   void* const exception_address = reinterpret_cast<void*>(info->si_addr);
