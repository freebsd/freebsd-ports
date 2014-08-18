--- spice3f5/common/src/lib/fte/clip.c.orig	1994-01-29 18:45:45 UTC
+++ spice3f5/common/src/lib/fte/clip.c
@@ -14,6 +14,7 @@ Author: 1982 Giles Billingsley
 #include "cpdefs.h"
 #include "ftedefs.h"
 #include "suffix.h"
+#include "util.h"
 
 #define POLYGONBUFSIZE 512
 /* XXX */
@@ -33,8 +34,10 @@ Author: 1982 Giles Billingsley
                          c |= CODEMAXY;
 
 /* XXX */
+/* Defined in "util.h".
 #define MAX(a, b) (((a) > (b)) ? (a) : (b))
 #define MIN(a, b) (((a) < (b)) ? (a) : (b))
+*/
 #define SWAPINT(a, b) { int xxxx = (a); (a) = (b); (b) = xxxx; }
 
 /* clip_line will clip a line to a rectangular area.  The returned
