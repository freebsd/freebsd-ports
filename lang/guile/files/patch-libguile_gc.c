--- libguile/gc.c.orig	2010-12-13 17:24:40 UTC
+++ libguile/gc.c
@@ -1060,6 +1060,20 @@ scm_ia64_ar_bsp (const void *opaque)
   return (void *) ctx->uc_mcontext.sc_ar_bsp;
 }
 # endif	/* linux */
+# ifdef __FreeBSD__
+#  include <ucontext.h>
+void *
+scm_ia64_register_backing_store_base (void)
+{
+  return (void *)0x8000000000000000;
+}
+void *
+scm_ia64_ar_bsp (const void *opaque)
+{
+  const ucontext_t *ctx = opaque;
+  return (void *)(ctx->uc_mcontext.mc_special.bspstore + ctx->uc_mcontext.mc_special.ndirty);
+}
+# endif /* __FreeBSD__ */
 #endif /* __ia64__ */
 
 void
