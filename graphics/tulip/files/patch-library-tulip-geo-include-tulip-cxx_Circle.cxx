--- library/tulip-geo/include/tulip/cxx/Circle.cxx.orig	2007-12-18 22:02:09.000000000 +0100
+++ library/tulip-geo/include/tulip/cxx/Circle.cxx	2007-12-18 22:06:10.000000000 +0100
@@ -45,7 +45,7 @@
   Vector<Obj,2> dir=c2-c1;
   Obj n=dir.norm();
   if (n==0)
-    return Circle<Obj>(c1,c1.radius >? c2.radius);
+    return Circle<Obj>(c1, (c1.radius > c2.radius) ? c1.radius : c2.radius);
   dir/=n;
   Vector<Obj,2> ext1=c1-dir*c1.radius;
   Vector<Obj,2> ext2=c2+dir*c2.radius;
@@ -64,16 +64,17 @@
   boundingBox[3]=(*it)[1]+(*it).radius;
   ++it;
   for (;it!=circles.end();++it) {
-    boundingBox[0]=boundingBox[0] <? ((*it)[0]-(*it).radius);
-    boundingBox[1]=boundingBox[1] <? ((*it)[1]-(*it).radius);
-    boundingBox[2]=boundingBox[2] >? ((*it)[0]+(*it).radius);
-    boundingBox[3]=boundingBox[3] >? ((*it)[1]+(*it).radius);
+    boundingBox[0]=(boundingBox[0] < ((*it)[0]-(*it).radius)) ? boundingBox[0] : ((*it)[0]-(*it).radius);
+    boundingBox[1]=(boundingBox[1] < ((*it)[1]-(*it).radius)) ? boundingBox[1] : ((*it)[1]-(*it).radius);
+    boundingBox[2]=(boundingBox[2] > ((*it)[0]+(*it).radius)) ? boundingBox[1] : ((*it)[0]-(*it).radius);
+    boundingBox[3]=(boundingBox[3] > ((*it)[1]+(*it).radius)) ? boundingBox[3] : ((*it)[1]-(*it).radius);
   }
 
   tlp::geo::Vector<Obj,2> center;
   center[0]=(boundingBox[0]+boundingBox[2])/2;
   center[1]=(boundingBox[1]+boundingBox[3])/2;
-  Obj radius = ((boundingBox[2]-boundingBox[0])/2 ) >? ( (boundingBox[3]-boundingBox[1])/2 );
+  Obj radius = (((boundingBox[2]-boundingBox[0])/2 ) > ( (boundingBox[3]-boundingBox[1])/2 )) ?
+               ((boundingBox[2]-boundingBox[0])/2 ) : ( (boundingBox[3]-boundingBox[1])/2 );
   tlp::geo::Circle<Obj> result(center,radius);
   //compute circle hull
   for (typename std::vector< tlp::geo::Circle<Obj> >::const_iterator it=circles.begin();it!=circles.end();++it) 
