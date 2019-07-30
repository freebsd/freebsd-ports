--- src/sljit/sljitConfigInternal.h.orig	2018-08-13 10:18:10 UTC
+++ src/sljit/sljitConfigInternal.h
@@ -530,7 +530,7 @@ typedef double sljit_f64;
 #endif /* !SLJIT_FUNC */
 
 #ifndef SLJIT_INDIRECT_CALL
-#if ((defined SLJIT_CONFIG_PPC_64 && SLJIT_CONFIG_PPC_64) && (defined SLJIT_BIG_ENDIAN && SLJIT_BIG_ENDIAN)) \
+#if ((defined SLJIT_CONFIG_PPC_64 && SLJIT_CONFIG_PPC_64) && (!defined _CALL_ELF || _CALL_ELF == 1)) \
 	|| ((defined SLJIT_CONFIG_PPC_32 && SLJIT_CONFIG_PPC_32) && defined _AIX)
 /* It seems certain ppc compilers use an indirect addressing for functions
    which makes things complicated. */
