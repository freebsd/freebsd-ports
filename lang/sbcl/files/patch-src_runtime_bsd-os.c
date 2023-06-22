--- src/runtime/bsd-os.c.orig	2023-05-28 10:34:18 UTC
+++ src/runtime/bsd-os.c
@@ -283,11 +283,7 @@ os_install_interrupt_handlers(void)
 os_install_interrupt_handlers(void)
 {
     if (INSTALL_SIG_MEMORY_FAULT_HANDLER) {
-    ll_install_handler(SIG_MEMORY_FAULT,
-#if defined(LISP_FEATURE_FREEBSD) && !defined(__GLIBC__)
-                                                 (__siginfohandler_t *)
-#endif
-                                                 memory_fault_handler);
+    ll_install_handler(SIG_MEMORY_FAULT, memory_fault_handler);
 
 #ifdef LISP_FEATURE_DARWIN
     /* Unmapped pages get this and not SIGBUS. */
