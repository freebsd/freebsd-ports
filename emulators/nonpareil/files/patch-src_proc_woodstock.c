--- src.orig/proc_woodstock.c	Thu Jul 27 18:10:44 2006
+++ src/proc_woodstock.c	Thu Jul 27 18:12:03 2006
@@ -36,6 +36,9 @@
 #include "proc_woodstock.h"
 #include "dis_woodstock.h"
 
+#ifndef PRId64
+#define PRId64 "lld"
+#endif
 
 /* If defined, print warnings about stack overflow or underflow. */
 #undef STACK_WARNING
