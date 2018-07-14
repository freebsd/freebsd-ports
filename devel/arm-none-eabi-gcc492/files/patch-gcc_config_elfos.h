--- gcc/config/elfos.h.orig	2014-04-07 13:27:39 UTC
+++ gcc/config/elfos.h
@@ -99,7 +99,7 @@ see the files COPYING3 and COPYING.RUNTI
 
 #undef  ASM_OUTPUT_SKIP
 #define ASM_OUTPUT_SKIP(FILE, SIZE) \
-   fprintf ((FILE), "%s"HOST_WIDE_INT_PRINT_UNSIGNED"\n",\
+   fprintf ((FILE), "%s" HOST_WIDE_INT_PRINT_UNSIGNED "\n",\
 	    SKIP_ASM_OP, (SIZE))
 
 /* This is how to store into the string LABEL
@@ -167,7 +167,7 @@ see the files COPYING3 and COPYING.RUNTI
     {									\
       fprintf ((FILE), "%s", COMMON_ASM_OP);				\
       assemble_name ((FILE), (NAME));					\
-      fprintf ((FILE), ","HOST_WIDE_INT_PRINT_UNSIGNED",%u\n",		\
+      fprintf ((FILE), "," HOST_WIDE_INT_PRINT_UNSIGNED ",%u\n",	\
 	       (SIZE), (ALIGN) / BITS_PER_UNIT);			\
     }									\
   while (0)
