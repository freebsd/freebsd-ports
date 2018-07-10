--- gcc/config/ia64/ia64.c.orig	2013-01-10 20:38:27 UTC
+++ gcc/config/ia64/ia64.c
@@ -798,7 +798,7 @@ ia64_vms_output_aligned_decl_common (FIL
 
   /*  Code from elfos.h.  */
   assemble_name (file, name);
-  fprintf (file, ","HOST_WIDE_INT_PRINT_UNSIGNED",%u",
+  fprintf (file, "," HOST_WIDE_INT_PRINT_UNSIGNED ",%u",
            size, align / BITS_PER_UNIT);
 
   fputc ('\n', file);
@@ -9959,7 +9959,7 @@ process_cfa_adjust_cfa (FILE *asm_out_fi
 	      gcc_assert (!frame_pointer_needed);
 	      if (unwind)
 		fprintf (asm_out_file,
-			 "\t.fframe "HOST_WIDE_INT_PRINT_DEC"\n",
+			 "\t.fframe " HOST_WIDE_INT_PRINT_DEC "\n",
 			 -INTVAL (op1));
 	    }
 	  else
