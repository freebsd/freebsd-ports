--- src/sljit/sljitNativePPC_common.c.orig	2018-01-06 15:12:56 UTC
+++ src/sljit/sljitNativePPC_common.c
@@ -42,7 +42,7 @@ typedef sljit_u32 sljit_ins;
 #include <sys/cache.h>
 #endif
 
-#if (defined SLJIT_LITTLE_ENDIAN && SLJIT_LITTLE_ENDIAN)
+#if (defined _CALL_ELF && _CALL_ELF == 2)
 #define SLJIT_PASS_ENTRY_ADDR_TO_CALL 1
 #endif
 
