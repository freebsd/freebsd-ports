--- nurbs/nurbsSub.cpp.orig	Mon May 13 14:07:46 2002
+++ nurbs/nurbsSub.cpp	Fri Dec  1 01:04:05 2006
@@ -904,7 +904,7 @@
   
   /* Allocate storage for the grid of points generated */
   
-  CHECK( pts = new (SurfSample<T>*)[Granularity+1]);
+  CHECK( pts = new SurfSample<T>* [Granularity+1]);
   CHECK( pts[0] = new SurfSample<T>[(Granularity+1)*(Granularity+1)]);
   
   for (i = 1; i <= Granularity; i++)
@@ -983,7 +983,7 @@
   
   if (! *alpha)	/* Must allocate alpha */
     {
-      CHECK( *alpha = new (T*)[k+1]);
+      CHECK( *alpha = new T* [k+1]);
       for (i = 0; i <= k; i++)
 	CHECK( (*alpha)[i] = new T[(m + n + 1)]);
     }
