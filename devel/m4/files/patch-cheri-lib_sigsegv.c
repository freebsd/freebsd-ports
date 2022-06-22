--- lib/sigsegv.c.orig
+++ lib/sigsegv.c
@@ -353,7 +353,11 @@
 
 /* See sys/arm64/include/ucontext.h.  */
 
+#ifdef __CHERI_PURE_CAPABILITY__
+#   define SIGSEGV_FAULT_STACKPOINTER  ((ucontext_t *) ucp)->uc_mcontext.mc_capregs.cap_sp
+#else
 #   define SIGSEGV_FAULT_STACKPOINTER  ((ucontext_t *) ucp)->uc_mcontext.mc_gpregs.gp_sp
+#endif
 
 #  elif defined __arm__ || defined __armhf__ /* 32-bit */
 
