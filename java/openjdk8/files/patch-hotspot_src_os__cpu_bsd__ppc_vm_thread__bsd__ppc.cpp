--- hotspot/src/os_cpu/bsd_ppc/vm/thread_bsd_ppc.cpp.orig	2021-08-04 17:59:22 UTC
+++ hotspot/src/os_cpu/bsd_ppc/vm/thread_bsd_ppc.cpp
@@ -24,7 +24,7 @@
  */
 
 #include "precompiled.hpp"
-#include "runtime/frame.hpp"
+#include "runtime/frame.inline.hpp"
 #include "runtime/thread.hpp"
 
 bool JavaThread::pd_get_top_frame_for_profiling(frame* fr_addr, void* ucontext, bool isInJava) {
@@ -42,7 +42,7 @@ bool JavaThread::pd_get_top_frame_for_profiling(frame*
   // if we were running Java code when SIGPROF came in.
   if (isInJava) {
     ucontext_t* uc = (ucontext_t*) ucontext;
-    frame ret_frame((intptr_t*)uc->>uc_mcontext.mc_gpr[1/*REG_SP*/],
+    frame ret_frame((intptr_t*)uc->uc_mcontext.mc_gpr[1/*REG_SP*/],
                      (address)uc->uc_mcontext.mc_srr0);
 
     if (ret_frame.pc() == NULL) {
@@ -83,11 +83,6 @@ bool JavaThread::pd_get_top_frame_for_profiling(frame*
 bool JavaThread::pd_get_top_frame_for_signal_handler(frame* fr_addr, void* ucontext, bool isInJava) {
   assert(this->is_Java_thread(), "must be JavaThread");
   return pd_get_top_frame_for_profiling(fr_addr, ucontext, isInJava);
-}
-// Forte Analyzer AsyncGetCallTrace profiling support is not implemented on Bsd/PPC.
-bool JavaThread::pd_get_top_frame_for_signal_handler(frame* fr_addr, void* ucontext, bool isInJava) {
-  Unimplemented();
-  return false;
 }
 
 void JavaThread::cache_global_variables() { }
