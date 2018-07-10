--- gcc/config/rx/rx.h.orig	2013-01-10 20:38:27 UTC
+++ gcc/config/rx/rx.h
@@ -549,15 +549,15 @@ typedef unsigned int CUMULATIVE_ARGS;
 	  switch ((ALIGN) / BITS_PER_UNIT)				\
             {								\
             case 4:							\
-              fprintf ((FILE), ":\t.BLKL\t"HOST_WIDE_INT_PRINT_UNSIGNED"\n",\
+              fprintf ((FILE), ":\t.BLKL\t" HOST_WIDE_INT_PRINT_UNSIGNED "\n",\
 		       (SIZE) / 4);					\
 	      break;							\
             case 2:							\
-              fprintf ((FILE), ":\t.BLKW\t"HOST_WIDE_INT_PRINT_UNSIGNED"\n",\
+              fprintf ((FILE), ":\t.BLKW\t" HOST_WIDE_INT_PRINT_UNSIGNED "\n",\
 		       (SIZE) / 2);					\
 	      break;							\
             default:							\
-              fprintf ((FILE), ":\t.BLKB\t"HOST_WIDE_INT_PRINT_UNSIGNED"\n",\
+              fprintf ((FILE), ":\t.BLKB\t" HOST_WIDE_INT_PRINT_UNSIGNED "\n",\
 		       (SIZE));						\
 	      break;							\
             }								\
@@ -566,7 +566,7 @@ typedef unsigned int CUMULATIVE_ARGS;
         {								\
           fprintf ((FILE), "%s", COMMON_ASM_OP);			\
           assemble_name ((FILE), (NAME));				\
-          fprintf ((FILE), ","HOST_WIDE_INT_PRINT_UNSIGNED",%u\n",	\
+          fprintf ((FILE), "," HOST_WIDE_INT_PRINT_UNSIGNED ",%u\n",	\
 	           (SIZE), (ALIGN) / BITS_PER_UNIT);			\
 	}								\
     }									\
