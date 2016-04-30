--- lib/database/src/so/nodes/nurbs/libnurbs/arctess.c++.orig	2000-08-15 12:56:22 UTC
+++ lib/database/src/so/nodes/nurbs/libnurbs/arctess.c++
@@ -247,8 +247,8 @@ ArcTessellator::pwl( Arc *arc, REAL s1, 
 
 /*    if(rate <= 0.06) rate = 0.06;*/
 
-    int snsteps = 1 + (int) (abs(s2 - s1) / rate );
-    int tnsteps = 1 + (int) (abs(t2 - t1) / rate );
+    int snsteps = 1 + (int) (absr(s2 - s1) / rate );
+    int tnsteps = 1 + (int) (absr(t2 - t1) / rate );
     int nsteps = max(1,max( snsteps, tnsteps ));
 
     REAL sstepsize = (s2 - s1) / (REAL) nsteps;
@@ -395,8 +395,8 @@ ArcTessellator::tessellateNonlinear( Arc
             vert->param[0] = u/w;
     	    vert->param[1] = v/w;
 #ifndef NOELIMINATION
-	    REAL ds = abs(vert[0].param[0] - vert[-1].param[0]);
-	    REAL dt = abs(vert[0].param[1] - vert[-1].param[1]);
+	    REAL ds = absr(vert[0].param[0] - vert[-1].param[0]);
+	    REAL dt = absr(vert[0].param[1] - vert[-1].param[1]);
 	    int canremove = (ds<geo_stepsize && dt<geo_stepsize) ? 1 : 0;
 	    REAL ods=0.0, odt=0.0;
 
@@ -454,8 +454,8 @@ ArcTessellator::tessellateNonlinear( Arc
             vert->param[0] = u;
 	    vert->param[1] = v;
 #ifndef NOELIMINATION
-	    REAL ds = abs(vert[0].param[0] - vert[-1].param[0]);
-	    REAL dt = abs(vert[0].param[1] - vert[-1].param[1]);
+	    REAL ds = absr(vert[0].param[0] - vert[-1].param[0]);
+	    REAL dt = absr(vert[0].param[1] - vert[-1].param[1]);
 	    int canremove = (ds<geo_stepsize && dt<geo_stepsize) ? 1 : 0;
 	    REAL ods=0.0, odt=0.0;
 
