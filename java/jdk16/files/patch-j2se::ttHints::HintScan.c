$FreeBSD$

--- ../../j2se/src/share/native/sun/font/t2k/ttHints/HintScan.c	6 Mar 2007 16:53:10 -0000	1.1.1.2
+++ ../../j2se/src/share/native/sun/font/t2k/ttHints/HintScan.c	31 Jul 2007 04:07:56 -0000
@@ -34,8 +34,6 @@
 
 #include "HintScan.h"
 
-#include "cpu.h" //for fastint 
-
 /* copy macros as temporal solution - straightforward including cause compilation issues */
 #define F26Dot6ToFixed(x)        ((x) << 10)
 #define IntToFixed(a)       ((Fixed)(a) << 16)
@@ -208,8 +206,8 @@
 	 F26Dot6 *v, tv, vmin, vmax, ctr;
 	F26Dot6 xmin, xmax, ymin, ymax;
 	tt_int32 n;
-	fastInt aPoint, startPoint, endPoint;
-	fastInt firstTime = true;
+	short aPoint, startPoint, endPoint;
+	short firstTime = true;
 	tt_int32 numPts = 0;
 	
 	if (t->numberOfContours > 0) {
