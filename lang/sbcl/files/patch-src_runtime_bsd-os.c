--- src/runtime/bsd-os.c.orig	2009-08-09 14:54:09.000000000 +0400
+++ src/runtime/bsd-os.c	2009-08-09 14:56:20.000000000 +0400
@@ -198,19 +198,9 @@
  */
 
 void
-memory_fault_handler(int signal, siginfo_t *siginfo, os_context_t *context
-#if defined(LISP_FEATURE_FREEBSD) && defined(LISP_FEATURE_X86_64)
-/* FreeBSD/amd64 stores fault address only in undocumented 4th arg. */
-                     ,void *fault_addr
-#endif
-    )
-{
-#if defined(LISP_FEATURE_FREEBSD) && defined(LISP_FEATURE_X86_64)
-    /* KLUDGE: Store fault address into si_addr for compatibilities. */
-    siginfo->si_addr = fault_addr;
-#else
+memory_fault_handler(int signal, siginfo_t *siginfo, os_context_t *context)
+{
     void *fault_addr = arch_get_bad_addr(signal, siginfo, context);
-#endif
 
 #if defined(LISP_FEATURE_RESTORE_TLS_SEGMENT_REGISTER_FROM_CONTEXT)
     FSHOW_SIGNAL((stderr, "/ TLS: restoring fs: %p in memory_fault_handler\n",
@@ -393,7 +383,7 @@
 #endif /* LISP_FEATURE_X86 */
 }
 
-#if defined(LISP_FEATURE_SB_THREAD) && !defined(LISP_FEATURE_SB_PTHREAD_FUTEX)
+#if defined(LISP_FEATURE_SB_THREAD) && !defined(LISP_FEATURE_SB_PTHREAD_FUTEX) && !defined(LISP_FEATURE_SB_LUTEX)
 int
 futex_wait(int *lock_word, long oldval, long sec, unsigned long usec)
 {
