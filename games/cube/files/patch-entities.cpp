--- entities.cpp.orig	2015-02-14 01:42:48.128349000 +0100
+++ entities.cpp	2015-02-14 01:44:19.309526000 +0100
@@ -25,9 +25,9 @@
         entity &e = ents[i];
         if(e.type==MAPMODEL)
         {
-            mapmodelinfo &mmi = getmminfo(e.attr2);
-            if(!&mmi) continue;
-			rendermodel(mmi.name, 0, 1, e.attr4, (float)mmi.rad, e.x, (float)S(e.x, e.y)->floor+mmi.zoff+e.attr3, e.y, (float)((e.attr1+7)-(e.attr1+7)%15), 0, false, 1.0f, 10.0f, mmi.snap);
+            mapmodelinfo *mmi = getmminfo(e.attr2);
+            if(!mmi) continue;
+			rendermodel(mmi->name, 0, 1, e.attr4, (float)mmi->rad, e.x, (float)S(e.x, e.y)->floor+mmi->zoff+e.attr3, e.y, (float)((e.attr1+7)-(e.attr1+7)%15), 0, false, 1.0f, 10.0f, mmi->snap);
         }
         else
         {
