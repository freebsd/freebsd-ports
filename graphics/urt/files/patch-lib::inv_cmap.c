--- lib/inv_cmap.c.orig	Thu Mar 10 21:28:37 2005
+++ lib/inv_cmap.c	Thu Mar 10 21:29:06 2005
@@ -42,7 +42,7 @@
 static long cbinc, cginc, crinc;
 static unsigned long *gdp, *rdp, *cdp;
 static unsigned char *grgbp, *rrgbp, *crgbp;
-static gstride, rstride;
+static int gstride, rstride;
 static long x, xsqr, colormax;
 static int cindex;
 #ifdef INSTRUMENT_IT
