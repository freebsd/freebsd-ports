--- gcc/config/pa/pa.c.orig	2013-04-06 17:46:50 UTC
+++ gcc/config/pa/pa.c
@@ -8672,7 +8672,7 @@ pa_asm_output_aligned_bss (FILE *stream,
 
   fprintf (stream, "\t.align %u\n", align / BITS_PER_UNIT);
   ASM_OUTPUT_LABEL (stream, name);
-  fprintf (stream, "\t.block "HOST_WIDE_INT_PRINT_UNSIGNED"\n", size);
+  fprintf (stream, "\t.block " HOST_WIDE_INT_PRINT_UNSIGNED "\n", size);
 }
 
 /* Both the HP and GNU assemblers under HP-UX provide a .comm directive
@@ -8702,7 +8702,7 @@ pa_asm_output_aligned_common (FILE *stre
   switch_to_section (bss_section);
 
   assemble_name (stream, name);
-  fprintf (stream, "\t.comm "HOST_WIDE_INT_PRINT_UNSIGNED"\n",
+  fprintf (stream, "\t.comm " HOST_WIDE_INT_PRINT_UNSIGNED "\n",
            MAX (size, align / BITS_PER_UNIT));
 }
 
@@ -8729,7 +8729,7 @@ pa_asm_output_aligned_local (FILE *strea
 #endif
 
   ASM_OUTPUT_LABEL (stream, name);
-  fprintf (stream, "\t.block "HOST_WIDE_INT_PRINT_UNSIGNED"\n", size);
+  fprintf (stream, "\t.block " HOST_WIDE_INT_PRINT_UNSIGNED "\n", size);
 }
 
 /* Returns 1 if the 6 operands specified in OPERANDS are suitable for
