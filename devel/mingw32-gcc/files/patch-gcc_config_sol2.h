--- gcc/config/sol2.h.orig	2013-01-10 20:38:27 UTC
+++ gcc/config/sol2.h
@@ -250,7 +250,7 @@ along with GCC; see the file COPYING3.  
 	switch_to_section (bss_section);				\
       fprintf ((FILE), "%s", COMMON_ASM_OP);				\
       assemble_name ((FILE), (NAME));					\
-      fprintf ((FILE), ","HOST_WIDE_INT_PRINT_UNSIGNED",%u\n",		\
+      fprintf ((FILE), "," HOST_WIDE_INT_PRINT_UNSIGNED ",%u\n",		\
 	       (SIZE), (ALIGN) / BITS_PER_UNIT);			\
     }									\
   while (0)
