--- src/runtime/ppc64-assem.S.orig
+++ src/runtime/ppc64-assem.S
@@ -259,7 +259,7 @@
 
 	/* "When a function is entered through its global entry point,
 	 * register r12 contains the entry-point address." */
-#ifdef LISP_FEATURE_BIG_ENDIAN
+#ifdef LISP_FEATURE_PPC64_ELFV1
 	mfctr 11
 	ld reg_CFUNC, 0(11)
 	/* In the v1 64-bit ABI, a function pointer is a pointer to a
@@ -273,6 +273,9 @@
 	// ld 11, 16(11)
 	mtctr reg_CFUNC
 #else
+	/* ELFv2: the call target is the function's address itself; reg_CFUNC
+	 * is r12, which the global entry point uses to set up its own TOC.
+	 * No descriptor indirection. */
 	mfctr reg_CFUNC
 #endif
         /* Into C we go. */
