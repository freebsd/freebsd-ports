--- dwarfout.c.orig	Thu Oct 26 18:40:07 1995
+++ dwarfout.c	Mon Mar 20 13:29:11 2000
@@ -1095,7 +1095,7 @@
 	byte |= 0x80;
       fprintf (asm_out_file, "\t%s\t0x%x", ASM_BYTE_OP, (unsigned) byte);
       if (flag_verbose_asm && value == 0)
-	fprintf (asm_out_file, "\t%s ULEB128 number - value = %u",
+	fprintf (asm_out_file, "\t%s ULEB128 number - value = %lu",
 		 ASM_COMMENT_START, orig_value);
       fputc ('\n', asm_out_file);
     }
@@ -1127,7 +1127,7 @@
 	}
       fprintf (asm_out_file, "\t%s\t0x%x", ASM_BYTE_OP, (unsigned) byte);
       if (flag_verbose_asm && more == 0)
-	fprintf (asm_out_file, "\t%s SLEB128 number - value = %d",
+	fprintf (asm_out_file, "\t%s SLEB128 number - value = %ld",
 		 ASM_COMMENT_START, orig_value);
       fputc ('\n', asm_out_file);
     }
