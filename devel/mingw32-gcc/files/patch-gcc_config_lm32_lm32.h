--- gcc/config/lm32/lm32.h.orig	2013-01-10 20:38:27 UTC
+++ gcc/config/lm32/lm32.h
@@ -438,7 +438,7 @@ do 									\
       switch_to_section (bss_section);					\
       fprintf ((FILE), "%s", COMMON_ASM_OP);				\
       assemble_name ((FILE), (NAME));					\
-      fprintf ((FILE), ","HOST_WIDE_INT_PRINT_UNSIGNED",%u\n",          \
+      fprintf ((FILE), "," HOST_WIDE_INT_PRINT_UNSIGNED ",%u\n",          \
                (SIZE), (ALIGN) / BITS_PER_UNIT);	                \
     }									\
 }									\
