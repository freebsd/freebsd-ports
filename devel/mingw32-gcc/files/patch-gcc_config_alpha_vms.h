--- gcc/config/alpha/vms.h.orig	2013-01-10 20:38:27 UTC
+++ gcc/config/alpha/vms.h
@@ -219,7 +219,7 @@ typedef struct {int num_args; enum avms_
 /* This is how to advance the location counter by SIZE bytes.  */
 
 #define ASM_OUTPUT_SKIP(FILE,SIZE)  \
-  fprintf (FILE, "\t.space "HOST_WIDE_INT_PRINT_UNSIGNED"\n", (SIZE))
+  fprintf (FILE, "\t.space " HOST_WIDE_INT_PRINT_UNSIGNED "\n", (SIZE))
 
 /* This says how to output an assembler line
    to define a global common symbol.  */
@@ -227,7 +227,7 @@ typedef struct {int num_args; enum avms_
 #define ASM_OUTPUT_LOCAL(FILE, NAME, SIZE,ROUNDED)	\
 ( fputs ("\t.lcomm ", (FILE)),				\
   assemble_name ((FILE), (NAME)),			\
-  fprintf ((FILE), ","HOST_WIDE_INT_PRINT_UNSIGNED"\n", (SIZE)))
+  fprintf ((FILE), "," HOST_WIDE_INT_PRINT_UNSIGNED "\n", (SIZE)))
 
 /* Switch into a generic section.  */
 #define TARGET_ASM_NAMED_SECTION vms_asm_named_section
