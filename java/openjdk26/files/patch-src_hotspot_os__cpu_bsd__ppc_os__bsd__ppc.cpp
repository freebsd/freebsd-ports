--- src/hotspot/os_cpu/bsd_ppc/os_bsd_ppc.cpp.orig	2026-04-13 11:53:22 UTC
+++ src/hotspot/os_cpu/bsd_ppc/os_bsd_ppc.cpp
@@ -179,7 +179,7 @@ intptr_t* os::fetch_bcp_from_context(const void* ucVoi
   assert(ucVoid != nullptr, "invariant");
   const ucontext_t* uc = (const ucontext_t*)ucVoid;
   assert(os::Posix::ucontext_is_interpreter(uc), "invariant");
-  return reinterpret_cast<intptr_t*>(uc->uc_mcontext.regs->gpr[14]); // R14_bcp
+  return reinterpret_cast<intptr_t*>(uc->uc_mcontext.mc_gpr[14]); // R14_bcp
 }
 
 frame os::get_sender_for_C_frame(frame* fr) {
@@ -204,7 +204,6 @@ bool PosixSignals::pd_hotspot_signal_handler(int sig, 
   address stub = nullptr;
   address pc   = nullptr;
 
-  //%note os_trap_1
   if (info != nullptr && uc != nullptr && thread != nullptr) {
     pc = (address) os::Posix::ucontext_get_pc(uc);
 
@@ -279,15 +278,7 @@ bool PosixSignals::pd_hotspot_signal_handler(int sig, 
 
       CodeBlob *cb = nullptr;
       int stop_type = -1;
-      // Handle signal from NativeJump::patch_verified_entry().
-      if (sig == SIGILL && nativeInstruction_at(pc)->is_sigill_not_entrant()) {
-        if (TraceTraps) {
-          tty->print_cr("trap: not_entrant");
-        }
-        stub = SharedRuntime::get_handle_wrong_method_stub();
-      }
-
-      else if ((sig == (USE_POLL_BIT_ONLY ? SIGTRAP : SIGSEGV)) &&
+      if ((sig == (USE_POLL_BIT_ONLY ? SIGTRAP : SIGSEGV)) &&
                // A bsd-ppc64 kernel before 2.6.6 doesn't set si_addr on some segfaults
                // in 64bit mode (cf. http://www.kernel.org/pub/bsd/kernel/v2.6/ChangeLog-2.6.6),
                // especially when we try to read from the safepoint polling page. So the check
@@ -315,6 +306,17 @@ bool PosixSignals::pd_hotspot_signal_handler(int sig, 
         stub = SharedRuntime::polling_page_return_handler_blob()->entry_point();
       }
 
+      // SIGTRAP-based nmethod entry barriers.
+      else if (sig == SIGTRAP && TrapBasedNMethodEntryBarriers &&
+               nativeInstruction_at(pc)->is_sigtrap_nmethod_entry_barrier() &&
+               CodeCache::contains((void*) pc)) {
+        if (TraceTraps) {
+          tty->print_cr("trap: nmethod entry barrier at " INTPTR_FORMAT " (SIGTRAP)", p2i(pc));
+        }
+        stub = StubRoutines::method_entry_barrier();
+        uc->uc_mcontext.mc_lr = (uintptr_t)(pc + BytesPerInstWord); // emulate call by setting LR
+      }
+
       // SIGTRAP-based ic miss check in compiled code.
       else if (sig == SIGTRAP && TrapBasedICMissChecks &&
                nativeInstruction_at(pc)->is_sigtrap_ic_miss_check()) {
@@ -408,7 +410,8 @@ bool PosixSignals::pd_hotspot_signal_handler(int sig, 
                         // flushing of icache is not necessary.
         stub = pc + 4;  // continue with next instruction.
       }
-      else if (thread->thread_state() == _thread_in_vm &&
+      else if ((thread->thread_state() == _thread_in_vm ||
+                thread->thread_state() == _thread_in_native) &&
                sig == SIGBUS && thread->doing_unsafe_access()) {
         address next_pc = pc + 4;
         if (UnsafeMemoryAccess::contains_pc(pc)) {
@@ -419,6 +422,15 @@ bool PosixSignals::pd_hotspot_signal_handler(int sig, 
         return true;
       }
     }
+
+    // jni_fast_Get<Primitive>Field can trap at certain pc's if a GC kicks in
+    // and the heap gets shrunk before the field access.
+    if ((sig == SIGSEGV) || (sig == SIGBUS)) {
+      address addr = JNI_FastGetField::find_slowcase_pc(pc);
+      if (addr != (address)-1) {
+        stub = addr;
+      }
+    }
   }
 
   if (stub != nullptr) {
@@ -497,7 +509,7 @@ void os::print_register_info(outputStream *st, const v
       break;
     default:
       st->print("r%-2d=", n-3);
-      print_location(st, uc->uc_mcontext.mc_gpr[n-3]);
+      print_location(st, (intptr_t)uc->uc_mcontext.mc_gpr[n-3]);
       break;
     }
     ++n;
