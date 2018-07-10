--- gcc/config/sparc/sparc.h.orig	2013-04-11 00:59:01 UTC
+++ gcc/config/sparc/sparc.h
@@ -1684,7 +1684,7 @@ do {									\
     fprintf (FILE, "\t.align %d\n", (1<<(LOG)))
 
 #define ASM_OUTPUT_SKIP(FILE,SIZE)  \
-  fprintf (FILE, "\t.skip "HOST_WIDE_INT_PRINT_UNSIGNED"\n", (SIZE))
+  fprintf (FILE, "\t.skip " HOST_WIDE_INT_PRINT_UNSIGNED "\n", (SIZE))
 
 /* This says how to output an assembler line
    to define a global common symbol.  */
@@ -1692,7 +1692,7 @@ do {									\
 #define ASM_OUTPUT_COMMON(FILE, NAME, SIZE, ROUNDED)  \
 ( fputs ("\t.common ", (FILE)),		\
   assemble_name ((FILE), (NAME)),		\
-  fprintf ((FILE), ","HOST_WIDE_INT_PRINT_UNSIGNED",\"bss\"\n", (SIZE)))
+  fprintf ((FILE), "," HOST_WIDE_INT_PRINT_UNSIGNED ",\"bss\"\n", (SIZE)))
 
 /* This says how to output an assembler line to define a local common
    symbol.  */
@@ -1700,7 +1700,7 @@ do {									\
 #define ASM_OUTPUT_ALIGNED_LOCAL(FILE, NAME, SIZE, ALIGNED)		\
 ( fputs ("\t.reserve ", (FILE)),					\
   assemble_name ((FILE), (NAME)),					\
-  fprintf ((FILE), ","HOST_WIDE_INT_PRINT_UNSIGNED",\"bss\",%u\n",	\
+  fprintf ((FILE), "," HOST_WIDE_INT_PRINT_UNSIGNED ",\"bss\",%u\n",	\
 	   (SIZE), ((ALIGNED) / BITS_PER_UNIT)))
 
 /* A C statement (sans semicolon) to output to the stdio stream
