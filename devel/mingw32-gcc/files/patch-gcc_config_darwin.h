--- gcc/config/darwin.h.orig	2013-02-11 23:30:10 UTC
+++ gcc/config/darwin.h
@@ -530,7 +530,7 @@ extern GTY(()) int darwin_ms_struct;
 #define TARGET_ASM_LTO_END darwin_asm_lto_end
 
 #define ASM_OUTPUT_SKIP(FILE,SIZE)  \
-  fprintf (FILE, "\t.space "HOST_WIDE_INT_PRINT_UNSIGNED"\n", SIZE)
+  fprintf (FILE, "\t.space " HOST_WIDE_INT_PRINT_UNSIGNED "\n", SIZE)
 
 /* Give ObjC methods pretty symbol names.  */
 
