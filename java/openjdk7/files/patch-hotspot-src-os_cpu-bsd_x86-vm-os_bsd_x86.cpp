--- hotspot/src/os_cpu/bsd_x86/vm/os_bsd_x86.cpp.prev	2016-05-20 14:03:24.511067000 +0000
+++ hotspot/src/os_cpu/bsd_x86/vm/os_bsd_x86.cpp	2016-05-20 14:12:29.670620000 +0000
@@ -609,7 +609,11 @@
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
