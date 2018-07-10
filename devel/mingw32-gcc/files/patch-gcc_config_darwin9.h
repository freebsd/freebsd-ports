--- gcc/config/darwin9.h.orig	2013-01-10 20:38:27 UTC
+++ gcc/config/darwin9.h
@@ -54,7 +54,7 @@ along with GCC; see the file COPYING3.  
     fprintf ((FILE), "\t.comm ");						\
     assemble_name ((FILE), (NAME));					\
     if (_new_size == 0) _new_size = 1;					\
-    fprintf ((FILE), ","HOST_WIDE_INT_PRINT_UNSIGNED",%u\n",		\
+    fprintf ((FILE), "," HOST_WIDE_INT_PRINT_UNSIGNED ",%u\n",		\
 	     _new_size, floor_log2 ((ALIGN) / BITS_PER_UNIT));		\
   } while (0)
 
