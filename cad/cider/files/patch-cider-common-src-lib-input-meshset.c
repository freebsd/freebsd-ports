--- cider/common/src/lib/input/meshset.c.orig	Sun Jan 30 04:30:51 1994
+++ cider/common/src/lib/input/meshset.c	Sat Dec 23 19:52:47 2006
@@ -36,12 +36,14 @@
     double *, int *, int * );
 static int oneSideRatio( double, double, double *, int );
 static int twoSideRatio( double, double, double, double *, int, int );
+static int MESHspacing( MESHcard *, double *, double *, int *, int *, int * );
 #else
 static int oneSideSpacing();
 static int twoSideSpacing();
 static int maxLimSpacing();
 static int oneSideRatio();
 static int twoSideRatio();
+static int MESHspacing();
 #endif
 
 /* END OF HEADER */
