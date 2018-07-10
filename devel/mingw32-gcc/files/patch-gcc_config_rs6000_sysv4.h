--- gcc/config/rs6000/sysv4.h.orig	2013-01-10 20:38:27 UTC
+++ gcc/config/rs6000/sysv4.h
@@ -414,7 +414,7 @@ do {									\
     {									\
       fprintf (FILE, "%s", LCOMM_ASM_OP);				\
       assemble_name ((FILE), (NAME));					\
-      fprintf ((FILE), ","HOST_WIDE_INT_PRINT_UNSIGNED",%u\n",		\
+      fprintf ((FILE), "," HOST_WIDE_INT_PRINT_UNSIGNED ",%u\n",		\
 	       (SIZE), (ALIGN) / BITS_PER_UNIT);			\
     }									\
   ASM_OUTPUT_TYPE_DIRECTIVE (FILE, NAME, "object");			\
