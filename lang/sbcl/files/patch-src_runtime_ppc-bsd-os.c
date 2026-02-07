--- src/runtime/ppc-bsd-os.c.orig	2025-07-26 14:30:41 UTC
+++ src/runtime/ppc-bsd-os.c
@@ -7,33 +7,39 @@
 #include "thread.h"
 
 
-int *
+os_context_register_t *
 os_context_register_addr(os_context_t *context, int offset)
 {
 #if defined(LISP_FEATURE_NETBSD)
     return &context->uc_mcontext.__gregs[offset];
 #elif defined(LISP_FEATURE_OPENBSD)
     return &context->sc_frame.fixreg[offset];
+#elif defined(LISP_FEATURE_FREEBSD)
+    return &context->uc_mcontext.mc_frame[offset];
 #endif
 }
 
 #if defined(ARCH_HAS_STACK_POINTER) /* It's not defined on PPC. */
-int *
+os_context_register_t *
 os_context_sp_addr(os_context_t *context)
 {
 #if defined(LISP_FEATURE_NETBSD)
     return &(_UC_MACHINE_SP(context));
+#elif defined(LISP_FEATURE_FREEBSD)
+    return &context->uc_mcontext.mc_frame[1];
 #endif
 }
 #endif
 
-int *
+os_context_register_t *
 os_context_lr_addr(os_context_t *context)
 {
 #if defined(LISP_FEATURE_NETBSD)
     return &context->uc_mcontext.__gregs[_REG_LR];
 #elif defined(LISP_FEATURE_OPENBSD)
     return &context->sc_frame.lr;
+#elif defined(LISP_FEATURE_FREEBSD)
+    return &context->uc_mcontext.mc_lr;
 #endif
 }
 
@@ -44,6 +50,8 @@ os_context_ctr_addr(os_context_t *context)
     return &context->uc_mcontext.__gregs[_REG_CTR];
 #elif defined(LISP_FEATURE_OPENBSD)
     return &context->sc_frame.ctr;
+#elif defined(LISP_FEATURE_FREEBSD)
+    return &context->uc_mcontext.mc_ctr;
 #endif
 }
 
@@ -54,6 +62,8 @@ os_context_cr_addr(os_context_t *context)
     return &context->uc_mcontext.__gregs[_REG_CR];
 #elif defined(LISP_FEATURE_OPENBSD)
     return &context->sc_frame.cr;
+#elif defined(LISP_FEATURE_FREEBSD)
+    return &context->uc_mcontext.mc_cr;
 #endif
 }
 
