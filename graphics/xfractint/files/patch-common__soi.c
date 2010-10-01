--- ./common/soi.c.orig	2004-11-23 08:13:37.000000000 -0500
+++ ./common/soi.c	2010-01-27 13:52:46.000000000 -0500
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
