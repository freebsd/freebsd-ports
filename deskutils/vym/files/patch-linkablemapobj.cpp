--- linkablemapobj.cpp.orig	Fri Sep 24 16:50:15 2004
+++ linkablemapobj.cpp	Thu Oct 21 17:22:44 2004
@@ -6,6 +6,12 @@
 
 #include "version.h"
 
+#if !defined(HAVE_LRINTF)
+static inline long int lrint(double x)
+{
+    return (long)(rint(x));
+}
+#endif
 
 /////////////////////////////////////////////////////////////////
 // LinkableMapObj
@@ -400,7 +406,7 @@
 		lrint(p1y) );
 
 	double a;	// angle
-	if (abs(vx)<0.000001)
+	if (fabs(vx)<0.000001)
 		a=M_PI_2;
 	else
 		a=atan( vy / vx );
@@ -611,7 +617,7 @@
 	double pny;
 	double m;
 
-	if (abs(vx) <0.0001) 
+	if (fabs(vx) <0.0001) 
 		m=0;
 	else	
 		m=(vy / (vx*vx));
