--- gcc/dwarf2cfi.c.orig	2013-01-10 20:38:27 UTC
+++ gcc/dwarf2cfi.c
@@ -3149,7 +3149,7 @@ output_cfi_directive (FILE *f, dw_cfi_re
     case DW_CFA_offset_extended:
     case DW_CFA_offset_extended_sf:
       r = DWARF2_FRAME_REG_OUT (cfi->dw_cfi_oprnd1.dw_cfi_reg_num, 1);
-      fprintf (f, "\t.cfi_offset %lu, "HOST_WIDE_INT_PRINT_DEC"\n",
+      fprintf (f, "\t.cfi_offset %lu, " HOST_WIDE_INT_PRINT_DEC "\n",
 	       r, cfi->dw_cfi_oprnd2.dw_cfi_offset);
       break;
 
@@ -3172,7 +3172,7 @@ output_cfi_directive (FILE *f, dw_cfi_re
     case DW_CFA_def_cfa:
     case DW_CFA_def_cfa_sf:
       r = DWARF2_FRAME_REG_OUT (cfi->dw_cfi_oprnd1.dw_cfi_reg_num, 1);
-      fprintf (f, "\t.cfi_def_cfa %lu, "HOST_WIDE_INT_PRINT_DEC"\n",
+      fprintf (f, "\t.cfi_def_cfa %lu, " HOST_WIDE_INT_PRINT_DEC "\n",
 	       r, cfi->dw_cfi_oprnd2.dw_cfi_offset);
       break;
 
@@ -3190,7 +3190,7 @@ output_cfi_directive (FILE *f, dw_cfi_re
     case DW_CFA_def_cfa_offset:
     case DW_CFA_def_cfa_offset_sf:
       fprintf (f, "\t.cfi_def_cfa_offset "
-	       HOST_WIDE_INT_PRINT_DEC"\n",
+	       HOST_WIDE_INT_PRINT_DEC "\n",
 	       cfi->dw_cfi_oprnd1.dw_cfi_offset);
       break;
 
@@ -3207,13 +3207,13 @@ output_cfi_directive (FILE *f, dw_cfi_re
 	  fprintf (f, "\t.cfi_escape %#x,", DW_CFA_GNU_args_size);
 	  dw2_asm_output_data_uleb128_raw (cfi->dw_cfi_oprnd1.dw_cfi_offset);
 	  if (flag_debug_asm)
-	    fprintf (f, "\t%s args_size "HOST_WIDE_INT_PRINT_DEC,
+	    fprintf (f, "\t%s args_size " HOST_WIDE_INT_PRINT_DEC,
 		     ASM_COMMENT_START, cfi->dw_cfi_oprnd1.dw_cfi_offset);
 	  fputc ('\n', f);
 	}
       else
 	{
-	  fprintf (f, "\t.cfi_GNU_args_size "HOST_WIDE_INT_PRINT_DEC "\n",
+	  fprintf (f, "\t.cfi_GNU_args_size " HOST_WIDE_INT_PRINT_DEC "\n",
 		   cfi->dw_cfi_oprnd1.dw_cfi_offset);
 	}
       break;
