--- mainmenu.c.orig	Sun Jan 21 20:52:22 2007
+++ mainmenu.c	Sun Jan 21 20:53:27 2007
@@ -2,10 +2,14 @@
  */
 
 #include <stdio.h>
+#include <string.h>
 #include <math.h>
 #include "astro.h"
 #include "circum.h"
 #include "screen.h"
+
+static mm_calendar(Now *np, int force);
+static mm_nfmoon(double jd, double tzone, int m, int f);
 
 /* #define PC_GRAPHICS */
 #ifdef PC_GRAPHICS
