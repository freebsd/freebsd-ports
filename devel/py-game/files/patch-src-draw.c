--- src/draw.c.orig	Thu Oct 16 08:13:22 2003
+++ src/draw.c	Mon Nov 17 03:47:49 2003
@@ -26,17 +26,12 @@
 #include "pygame.h"
 #include <math.h>
 
-#ifdef _MSC_VER
-#pragma warning (disable:4244)
-
 float trunc(float d)
 {
     if (d >= 0)
         return floor(d);
     return ceil(d);
 }
-
-#endif
 
 #define FRAC(z) (z-trunc(z))
 #define INVFRAC(z) (1-(z-trunc(z)))
