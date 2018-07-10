--- gcc/config/microblaze/microblaze.h.orig	2013-03-14 15:43:23 UTC
+++ gcc/config/microblaze/microblaze.h
@@ -656,7 +656,7 @@ do {									\
     }                                                                   \
   fprintf (FILE, "%s", COMMON_ASM_OP);                                  \
   assemble_name ((FILE), (NAME));					\
-  fprintf ((FILE), ","HOST_WIDE_INT_PRINT_UNSIGNED",%u\n",		\
+  fprintf ((FILE), "," HOST_WIDE_INT_PRINT_UNSIGNED ",%u\n",		\
            (SIZE), (ALIGN) / BITS_PER_UNIT);                            \
   ASM_OUTPUT_TYPE_DIRECTIVE (FILE, NAME, "object");			\
 } while (0)
@@ -676,7 +676,7 @@ do {									\
     }                                                                   \
   fprintf (FILE, "%s", LCOMMON_ASM_OP);                                 \
   assemble_name ((FILE), (NAME));					\
-  fprintf ((FILE), ","HOST_WIDE_INT_PRINT_UNSIGNED",%u\n",		\
+  fprintf ((FILE), "," HOST_WIDE_INT_PRINT_UNSIGNED ",%u\n",		\
            (SIZE), (ALIGN) / BITS_PER_UNIT);                            \
   ASM_OUTPUT_TYPE_DIRECTIVE (FILE, NAME, "object");			\
 } while (0)
