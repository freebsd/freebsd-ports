Read the saved registers from FreeBSD's mcontext_t (mc_rip, mc_rsp,
... on amd64, mc_gpregs on aarch64) (series 0008).
FreeBSD-specific, not submitted upstream yet.
--- runtime/vm/signal_handler_linux.cc.orig	2026-09-29 08:00:52 UTC
+++ runtime/vm/signal_handler_linux.cc
@@ -15,10 +15,14 @@ uintptr_t SignalHandler::GetProgramCounter(const mcont
 
 #if defined(HOST_ARCH_IA32)
   pc = static_cast<uintptr_t>(mcontext.gregs[REG_EIP]);
+#elif defined(HOST_ARCH_X64) && defined(__FreeBSD__)
+  pc = static_cast<uintptr_t>(mcontext.mc_rip);
 #elif defined(HOST_ARCH_X64)
   pc = static_cast<uintptr_t>(mcontext.gregs[REG_RIP]);
 #elif defined(HOST_ARCH_ARM)
   pc = static_cast<uintptr_t>(mcontext.arm_pc);
+#elif defined(HOST_ARCH_ARM64) && defined(__FreeBSD__)
+  pc = static_cast<uintptr_t>(mcontext.mc_gpregs.gp_elr);
 #elif defined(HOST_ARCH_ARM64)
   pc = static_cast<uintptr_t>(mcontext.pc);
 #elif defined(HOST_ARCH_RISCV32)
@@ -36,6 +40,8 @@ uintptr_t SignalHandler::GetFramePointer(const mcontex
 
 #if defined(HOST_ARCH_IA32)
   fp = static_cast<uintptr_t>(mcontext.gregs[REG_EBP]);
+#elif defined(HOST_ARCH_X64) && defined(__FreeBSD__)
+  fp = static_cast<uintptr_t>(mcontext.mc_rbp);
 #elif defined(HOST_ARCH_X64)
   fp = static_cast<uintptr_t>(mcontext.gregs[REG_RBP]);
 #elif defined(HOST_ARCH_ARM)
@@ -47,6 +53,8 @@ uintptr_t SignalHandler::GetFramePointer(const mcontex
     // ARM mode.
     fp = static_cast<uintptr_t>(mcontext.arm_fp);
   }
+#elif defined(HOST_ARCH_ARM64) && defined(__FreeBSD__)
+  fp = static_cast<uintptr_t>(mcontext.mc_gpregs.gp_x[29]);
 #elif defined(HOST_ARCH_ARM64)
   fp = static_cast<uintptr_t>(mcontext.regs[29]);
 #elif defined(HOST_ARCH_RISCV32)
@@ -65,10 +73,14 @@ uintptr_t SignalHandler::GetCStackPointer(const mconte
 
 #if defined(HOST_ARCH_IA32)
   sp = static_cast<uintptr_t>(mcontext.gregs[REG_ESP]);
+#elif defined(HOST_ARCH_X64) && defined(__FreeBSD__)
+  sp = static_cast<uintptr_t>(mcontext.mc_rsp);
 #elif defined(HOST_ARCH_X64)
   sp = static_cast<uintptr_t>(mcontext.gregs[REG_RSP]);
 #elif defined(HOST_ARCH_ARM)
   sp = static_cast<uintptr_t>(mcontext.arm_sp);
+#elif defined(HOST_ARCH_ARM64) && defined(__FreeBSD__)
+  sp = static_cast<uintptr_t>(mcontext.mc_gpregs.gp_sp);
 #elif defined(HOST_ARCH_ARM64)
   sp = static_cast<uintptr_t>(mcontext.sp);
 #elif defined(HOST_ARCH_RISCV32)
@@ -82,7 +94,10 @@ uintptr_t SignalHandler::GetDartStackPointer(const mco
 }
 
 uintptr_t SignalHandler::GetDartStackPointer(const mcontext_t& mcontext) {
-#if defined(TARGET_ARCH_ARM64) && !defined(DART_INCLUDE_SIMULATOR)
+#if defined(TARGET_ARCH_ARM64) && !defined(DART_INCLUDE_SIMULATOR) &&       \
+    defined(__FreeBSD__)
+  return static_cast<uintptr_t>(mcontext.mc_gpregs.gp_x[SPREG]);
+#elif defined(TARGET_ARCH_ARM64) && !defined(DART_INCLUDE_SIMULATOR)
   return static_cast<uintptr_t>(mcontext.regs[SPREG]);
 #else
   return GetCStackPointer(mcontext);
@@ -98,6 +113,8 @@ uintptr_t SignalHandler::GetLinkRegister(const mcontex
   lr = 0;
 #elif defined(HOST_ARCH_ARM)
   lr = static_cast<uintptr_t>(mcontext.arm_lr);
+#elif defined(HOST_ARCH_ARM64) && defined(__FreeBSD__)
+  lr = static_cast<uintptr_t>(mcontext.mc_gpregs.gp_lr);
 #elif defined(HOST_ARCH_ARM64)
   lr = static_cast<uintptr_t>(mcontext.regs[30]);
 #elif defined(HOST_ARCH_RISCV32)
