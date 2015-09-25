--- stress-cpu.c.orig	2015-09-18 14:50:12 UTC
+++ stress-cpu.c
@@ -23,6 +23,7 @@
  *
  */
 #define _GNU_SOURCE
+#define _DECLARE_C99_LDBL_MATH 1
 
 #include <stdio.h>
 #include <stdlib.h>
