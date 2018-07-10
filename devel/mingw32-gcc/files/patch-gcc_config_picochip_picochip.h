--- gcc/config/picochip/picochip.h.orig	2013-01-10 20:38:27 UTC
+++ gcc/config/picochip/picochip.h
@@ -596,7 +596,7 @@ do {                                    
 /* Assembler Commands for Alignment  */
 
 #define ASM_OUTPUT_SKIP(STREAM,BYTES) \
-  fprintf(STREAM, ".skip "HOST_WIDE_INT_PRINT_UNSIGNED"\n", BYTES);
+  fprintf(STREAM, ".skip " HOST_WIDE_INT_PRINT_UNSIGNED "\n", BYTES);
 #define ASM_OUTPUT_ALIGN(STREAM,POWER) \
   fprintf(STREAM, ".align %u\n", 1 << POWER);
 
