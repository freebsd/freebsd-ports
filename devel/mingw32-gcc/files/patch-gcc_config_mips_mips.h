--- gcc/config/mips/mips.h.orig	2013-02-25 13:53:16 UTC
+++ gcc/config/mips/mips.h
@@ -2694,7 +2694,7 @@ do {									\
 
 #undef ASM_OUTPUT_SKIP
 #define ASM_OUTPUT_SKIP(STREAM,SIZE)					\
-  fprintf (STREAM, "\t.space\t"HOST_WIDE_INT_PRINT_UNSIGNED"\n", (SIZE))
+  fprintf (STREAM, "\t.space\t" HOST_WIDE_INT_PRINT_UNSIGNED "\n", (SIZE))
 
 /* This is how to output a string.  */
 #undef ASM_OUTPUT_ASCII
