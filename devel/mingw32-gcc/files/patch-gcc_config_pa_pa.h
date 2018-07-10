--- gcc/config/pa/pa.h.orig	2013-02-03 19:52:37 UTC
+++ gcc/config/pa/pa.h
@@ -1204,7 +1204,7 @@ do {									     \
     fprintf (FILE, "\t.align %d\n", (1<<(LOG)))
 
 #define ASM_OUTPUT_SKIP(FILE,SIZE)  \
-  fprintf (FILE, "\t.blockz "HOST_WIDE_INT_PRINT_UNSIGNED"\n",		\
+  fprintf (FILE, "\t.blockz " HOST_WIDE_INT_PRINT_UNSIGNED "\n",		\
 	   (unsigned HOST_WIDE_INT)(SIZE))
 
 /* This says how to output an assembler line to define an uninitialized
