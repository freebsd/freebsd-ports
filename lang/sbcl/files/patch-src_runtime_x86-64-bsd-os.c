--- src/runtime/x86-64-bsd-os.c.orig	2016-12-31 08:38:30 UTC
+++ src/runtime/x86-64-bsd-os.c
@@ -142,6 +142,13 @@ os_flush_icache(os_vm_address_t address,
 {
 }
 
+#ifdef LISP_FEATURE_SB_THREAD
+void
+arch_os_load_ldt(struct thread *thread)
+{
+}
+#endif
+
 int arch_os_thread_init(struct thread *thread) {
     stack_t sigstack;
 #ifdef LISP_FEATURE_SB_THREAD
