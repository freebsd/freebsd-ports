--- gcc/config/s390/s390.h.orig	2013-03-05 12:02:06 UTC
+++ gcc/config/s390/s390.h
@@ -822,7 +822,7 @@ do {									\
 
 /* Advance the location counter by SIZE bytes.  */
 #define ASM_OUTPUT_SKIP(FILE, SIZE) \
-  fprintf ((FILE), "\t.set\t.,.+"HOST_WIDE_INT_PRINT_UNSIGNED"\n", (SIZE))
+  fprintf ((FILE), "\t.set\t.,.+" HOST_WIDE_INT_PRINT_UNSIGNED "\n", (SIZE))
 
 /* The LOCAL_LABEL_PREFIX variable is used by dbxelf.h.  */
 #define LOCAL_LABEL_PREFIX "."
