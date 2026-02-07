--- physics.cpp.orig	2015-02-14 01:31:41.351723000 +0100
+++ physics.cpp	2015-02-14 01:40:28.770647000 +0100
@@ -46,14 +46,14 @@
     {
         entity &e = ents[i];
         if(e.type!=MAPMODEL) continue;
-        mapmodelinfo &mmi = getmminfo(e.attr2);
-        if(!&mmi || !mmi.h) continue;
-        const float r = mmi.rad+d->radius;
+        mapmodelinfo *mmi = getmminfo(e.attr2);
+        if(!mmi || !mmi->h) continue;
+        const float r = mmi->rad+d->radius;
         if(fabs(e.x-d->o.x)<r && fabs(e.y-d->o.y)<r)
         { 
-            float mmz = (float)(S(e.x, e.y)->floor+mmi.zoff+e.attr3);
+            float mmz = (float)(S(e.x, e.y)->floor+mmi->zoff+e.attr3);
             if(d->o.z-d->eyeheight<mmz) { if(mmz<hi) hi = mmz; }
-            else if(mmz+mmi.h>lo) lo = mmz+mmi.h;
+            else if(mmz+mmi->h>lo) lo = mmz+mmi->h;
         };
     };
 };
