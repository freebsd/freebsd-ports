--- src/runtime/ppc-arch.c.orig	2025-07-26 14:30:41 UTC
+++ src/runtime/ppc-arch.c
@@ -60,7 +60,7 @@ arch_get_bad_addr(int sig, siginfo_t *code, os_context
 {
     os_vm_address_t addr;
 
-#if defined(LISP_FEATURE_NETBSD) || defined(LISP_FEATURE_OPENBSD)
+#if defined(LISP_FEATURE_NETBSD) || defined(LISP_FEATURE_OPENBSD) || defined(LISP_FEATURE_FREEBSD)
     addr = (os_vm_address_t) (code->si_addr);
 #else
     addr = (os_vm_address_t) (*os_context_register_addr(context,PT_DAR));
