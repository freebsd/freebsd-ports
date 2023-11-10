--- src/hotspot/os_cpu/bsd_ppc/os_bsd_ppc.cpp.orig	2022-12-21 16:54:47 UTC
+++ src/hotspot/os_cpu/bsd_ppc/os_bsd_ppc.cpp
@@ -187,16 +187,6 @@ frame os::current_frame() {
 bool PosixSignals::pd_hotspot_signal_handler(int sig, siginfo_t* info,
                                              ucontext_t* uc, JavaThread* thread) {
 
-  // Moved SafeFetch32 handling outside thread!=NULL conditional block to make
-  // it work if no associated JavaThread object exists.
-  if (uc) {
-    address const pc = os::Posix::ucontext_get_pc(uc);
-    if (pc && StubRoutines::is_safefetch_fault(pc)) {
-      os::Posix::ucontext_set_pc(uc, StubRoutines::continuation_for_safefetch_fault(pc));
-      return true;
-    }
-  }
-
   // decide if this trap can be handled by a stub
   address stub = NULL;
   address pc   = NULL;
