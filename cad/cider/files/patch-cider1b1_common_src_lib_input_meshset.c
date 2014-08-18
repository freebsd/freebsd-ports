--- cider1b1/common/src/lib/input/meshset.c.orig	1994-01-29 19:30:51 UTC
+++ cider1b1/common/src/lib/input/meshset.c
@@ -36,12 +36,14 @@ static int maxLimSpacing( double, double
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
