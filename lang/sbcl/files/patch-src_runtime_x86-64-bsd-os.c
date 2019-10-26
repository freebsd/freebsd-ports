--- src/runtime/x86-64-bsd-os.c.orig	2019-10-26 17:02:04.948892000 +0200
+++ src/runtime/x86-64-bsd-os.c	2019-10-26 17:03:43.724206000 +0200
@@ -148,6 +148,13 @@
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
 #ifdef LISP_FEATURE_SB_THREAD
 #ifdef LISP_FEATURE_GCC_TLS
