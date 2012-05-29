--- vp_global.h.orig	1994-12-31 00:53:14.000000000 +0100
+++ vp_global.h	2012-05-29 12:52:59.931425126 +0200
@@ -36,7 +36,7 @@
 #include "volpack.h"
 
 #include <stdio.h>
-#include <malloc.h>
+#include <stdlib.h>
 #include <math.h>
 extern double rint ANSI_ARGS((double x)); /* missing from Ultrix math.h */
 
@@ -168,7 +168,7 @@
  * Macros.                                                         *
  *******************************************************************/
 
-#define NULL 0
+/* #define NULL 0 */
 
 #define MAX(a,b)        (((a)<(b)) ? (b) : (a))
 #define MIN(a,b)        (((a)>(b)) ? (b) : (a))
