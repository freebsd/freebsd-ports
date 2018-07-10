--- gcc/config/darwin.c.orig	2013-02-11 22:36:23 UTC
+++ gcc/config/darwin.c
@@ -2182,7 +2182,7 @@ fprintf (file, "# dadon: %s %s (%llu, %u
 
       ASM_OUTPUT_LABEL (file, xname);
       size = 1;
-      fprintf (file, "\t.space\t"HOST_WIDE_INT_PRINT_UNSIGNED"\n", size);
+      fprintf (file, "\t.space\t" HOST_WIDE_INT_PRINT_UNSIGNED "\n", size);
 
       /* Check that we've correctly picked up the zero-sized item and placed it
          properly.  */
@@ -2323,7 +2323,7 @@ darwin_emit_local_bss (FILE *fp, tree de
 	fprintf (fp, "\t.align\t%u\n", l2align);
 
       assemble_name (fp, name);        
-      fprintf (fp, ":\n\t.space\t"HOST_WIDE_INT_PRINT_UNSIGNED"\n", size);
+      fprintf (fp, ":\n\t.space\t" HOST_WIDE_INT_PRINT_UNSIGNED "\n", size);
     }
   else 
     {
@@ -2344,10 +2344,10 @@ darwin_emit_local_bss (FILE *fp, tree de
 	size = 1;
 
       if (l2align)
-	fprintf (fp, ","HOST_WIDE_INT_PRINT_UNSIGNED",%u\n",
+	fprintf (fp, "," HOST_WIDE_INT_PRINT_UNSIGNED ",%u\n",
 		 size, (unsigned) l2align);
       else
-	fprintf (fp, ","HOST_WIDE_INT_PRINT_UNSIGNED"\n", size);
+	fprintf (fp, "," HOST_WIDE_INT_PRINT_UNSIGNED "\n", size);
     }
 
   (*targetm.encode_section_info) (decl, DECL_RTL (decl), false);
@@ -2495,7 +2495,7 @@ fprintf (fp, "# albss: %s (%lld,%d) ro %
 	fprintf (fp, "\t.align\t%u\n", l2align);
 
       assemble_name (fp, name);
-      fprintf (fp, ":\n\t.space\t"HOST_WIDE_INT_PRINT_UNSIGNED"\n", size);
+      fprintf (fp, ":\n\t.space\t" HOST_WIDE_INT_PRINT_UNSIGNED "\n", size);
     }
   else 
     {
@@ -2516,9 +2516,9 @@ fprintf (fp, "# albss: %s (%lld,%d) ro %
 	size = 1;
 
       if (l2align)
-	fprintf (fp, ","HOST_WIDE_INT_PRINT_UNSIGNED",%u\n", size, l2align);
+	fprintf (fp, "," HOST_WIDE_INT_PRINT_UNSIGNED ",%u\n", size, l2align);
       else
-	fprintf (fp, ","HOST_WIDE_INT_PRINT_UNSIGNED"\n", size);
+	fprintf (fp, "," HOST_WIDE_INT_PRINT_UNSIGNED "\n", size);
     }
   (* targetm.encode_section_info) (decl, DECL_RTL (decl), false);
 }
