--- gcc/config/i386/bsd.h.orig	2013-01-10 20:38:27 UTC
+++ gcc/config/i386/bsd.h
@@ -46,7 +46,7 @@ along with GCC; see the file COPYING3.  
    that says to advance the location counter by SIZE bytes.  */
 
 #define ASM_OUTPUT_SKIP(FILE,SIZE)  \
-  fprintf (FILE, "\t.space "HOST_WIDE_INT_PRINT_UNSIGNED"\n", (SIZE))
+  fprintf (FILE, "\t.space " HOST_WIDE_INT_PRINT_UNSIGNED "\n", (SIZE))
 
 /* Define the syntax of labels and symbol definitions/declarations.  */
 
