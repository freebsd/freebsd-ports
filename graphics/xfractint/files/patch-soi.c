--- soi.c.orig	Tue Sep  7 00:38:10 1999
+++ soi.c	Sun Dec  7 02:59:00 2003
@@ -13,13 +13,19 @@
  */
 #include <time.h>
 #include <string.h>
+#ifndef BIG_ANSI_C
 #include <malloc.h>
+#endif
 #include "port.h"
 #include "prototyp.h"
 
 #define DBLS LDBL
 #define FABS(x)  fabsl(x)
+#ifdef __FreeBSD__
+#define FREXP(x,y) frexp(x,y)
+#else
 #define FREXP(x,y) frexpl(x,y)
+#endif
 
 #define TRUE 1
 #define FALSE 0
