--- mono/mini/tramp-amd64.c.orig	2018-04-13 23:37:57 UTC
+++ mono/mini/tramp-amd64.c
@@ -363,7 +363,11 @@ mono_arch_create_generic_trampoline (Mon
 	}
 	for (i = 0; i < AMD64_XMM_NREG; ++i)
 		if (AMD64_IS_ARGUMENT_XREG (i))
+#if defined(MONO_HAVE_SIMD_REG)
 			amd64_movdqu_membase_reg (code, AMD64_RBP, saved_fpregs_offset + (i * sizeof(MonoContextSimdReg)), i);
+#else
+			amd64_movsd_membase_reg (code, AMD64_RBP, saved_fpregs_offset + (i * sizeof(double)), i);
+#endif
 
 	/* Check that the stack is aligned */
 	amd64_mov_reg_reg (code, AMD64_R11, AMD64_RSP, sizeof (mgreg_t));
@@ -540,7 +544,11 @@ mono_arch_create_generic_trampoline (Mon
 			amd64_mov_reg_membase (code, i, AMD64_RBP, saved_regs_offset + (i * sizeof(mgreg_t)), sizeof(mgreg_t));
 	for (i = 0; i < AMD64_XMM_NREG; ++i)
 		if (AMD64_IS_ARGUMENT_XREG (i))
+#if defined(MONO_HAVE_SIMD_REG)
 			amd64_movdqu_reg_membase (code, i, AMD64_RBP, saved_fpregs_offset + (i * sizeof(MonoContextSimdReg)));
+#else
+			amd64_movsd_reg_membase (code, i, AMD64_RBP, saved_fpregs_offset + (i * sizeof(double)));
+#endif
 
 	/* Restore stack */
 #if TARGET_WIN32
