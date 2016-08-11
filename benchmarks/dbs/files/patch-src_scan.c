--- src/scan.c.orig	1997-07-11 00:54:12 UTC
+++ src/scan.c
@@ -49,6 +49,9 @@
  * $Author: yukio-m $
  *****************************************************************/
 
+#ifdef HAVE_SYS_PARAM_H
+#include <sys/param.h>
+#endif
 #include<stdio.h>
 #include<stdlib.h>
 
@@ -58,7 +61,8 @@
 #include <string.h>
 #endif
 
-#if !defined(bsdi)
+#if (!defined(BSD) || (BSD < 199306))
+#error BSD
 #include <malloc.h>
 #endif
 
