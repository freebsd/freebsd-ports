--- contrib/domhex/surfaceFiller.cpp.orig	2024-03-29 22:06:54 UTC
+++ contrib/domhex/surfaceFiller.cpp
@@ -85,10 +85,10 @@ bool compute4neighbors(
   metricField = SMetric3(1. / (L * L));
 
   // get the unit normal at that point
-  Pair<SVector3, SVector3> der =
+  std::pair<SVector3, SVector3> der =
     gf->firstDer(SPoint2(midpoint[0], midpoint[1]));
-  SVector3 s1 = der.first();
-  SVector3 s2 = der.second();
+  SVector3 s1 = der.first;
+  SVector3 s2 = der.second;
   SVector3 n = crossprod(s1, s2);
   n.normalize();
   t1 -= n*dot(t1,n);
@@ -259,10 +259,10 @@ bool compute4neighbors(
 //     //                 0
 
 //     // get the unit normal at that point
-//     Pair<SVector3, SVector3> der =
+//     std::pair<SVector3, SVector3> der =
 //       gf->firstDer(SPoint2(midpoint[0], midpoint[1]));
-//     SVector3 s1 = der.first();
-//     SVector3 s2 = der.second();
+//     SVector3 s1 = der.first;
+//     SVector3 s2 = der.second;
 //     SVector3 n = crossprod(s1, s2);
 //     n.normalize();
 
@@ -490,7 +490,7 @@ void packingOfParallelograms(GFace *gf, std::vector<MV
     double du[4] = {0,0,0,0}, dv[4]= {0,0,0,0};
 
     //    printf("cop %d\n",(*it)->getNum());
-    
+
     for (int i=0;i<2;i++){
       if (gf->periodic(i)){
 	reparamMeshVertexOnFace(*it, gf, midpoint);
@@ -513,7 +513,7 @@ void packingOfParallelograms(GFace *gf, std::vector<MV
     }
 
     if (NP == 0)NP=1;
-    
+
     for (int i=0;i<NP;i++){
       bool singular = !compute4neighbors(gf, *it, midpoint, newp, metricField, cross_field, du[i],dv[i],globalMult );
       //      printf("there %d %g %g\n",singular,du[i],dv[i]);
