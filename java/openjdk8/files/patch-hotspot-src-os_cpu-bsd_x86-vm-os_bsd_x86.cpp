--- hotspot/src/os_cpu/bsd_x86/vm/os_bsd_x86.cpp.orig	2016-05-20 12:24:21.966092000 +0100
+++ hotspot/src/os_cpu/bsd_x86/vm/os_bsd_x86.cpp	2016-05-20 12:46:40.522912000 +0100
@@ -594,7 +596,11 @@
           stub = SharedRuntime::continuation_for_implicit_exception(thread, pc, SharedRuntime::IMPLICIT_NULL);
       }
     } else if (thread->thread_state() == _thread_in_vm &&
+#ifdef __FreeBSD__
+               (sig == SIGBUS || sig == SIGSEGV) && 
+#else
                sig == SIGBUS && /* info->si_code == BUS_OBJERR && */
+#endif
                thread->doing_unsafe_access()) {
         stub = StubRoutines::handler_for_unsafe_access();
     }
