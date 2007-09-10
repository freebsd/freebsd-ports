--- soi.c.orig	Mon Apr  8 19:33:28 2002
+++ soi.c	Mon Sep  3 16:01:06 2007
@@ -13,7 +13,9 @@
  */
 #include <time.h>
 #include <string.h>
+#ifndef BIG_ANSI_C
 #include <malloc.h>
+#endif
 #include "port.h"
 #include "prototyp.h"
 
@@ -21,7 +23,7 @@
 #define FABS(x)  fabsl(x)
 /* the following needs to be changed back to frexpl once the portability
    issue has been addressed JCO */
-#ifndef XFRACT
+#ifndef __FreeBSD__
 #define FREXP(x,y) frexpl(x,y)
 #else
 #define FREXP(x,y) frexp(x,y)
