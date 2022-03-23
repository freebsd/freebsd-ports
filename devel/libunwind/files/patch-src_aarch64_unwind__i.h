--- src/aarch64/unwind_i.h.orig	2020-04-28 15:49:14 UTC
+++ src/aarch64/unwind_i.h
@@ -59,6 +59,10 @@ extern int aarch64_local_resume (unw_addr_space_t as, 
   } while (0)
 #endif
 
+#if defined(__FreeBSD__)
+#define GET_FPCTX(uc) ((unw_tdep_context_t *)(&uc->uc_mcontext.mc_spare))
+#else
 #define GET_FPCTX(uc) ((unw_fpsimd_context_t *)(&uc->uc_mcontext.__reserved))
+#endif
 
 #endif /* unwind_i_h */
