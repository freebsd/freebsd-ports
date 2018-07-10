--- gcc/config/picochip/picochip.c.orig	2013-01-10 20:38:27 UTC
+++ gcc/config/picochip/picochip.c
@@ -1701,7 +1701,7 @@ void
 picochip_asm_output_anchor (rtx symbol)
 {
   fprintf (asm_out_file, ".offsetData _%s, ",XSTR (symbol, 0));
-  fprintf (asm_out_file, "+ " HOST_WIDE_INT_PRINT_DEC"\n",SYMBOL_REF_BLOCK_OFFSET(symbol));
+  fprintf (asm_out_file, "+ " HOST_WIDE_INT_PRINT_DEC "\n",SYMBOL_REF_BLOCK_OFFSET(symbol));
 }
 
 void
