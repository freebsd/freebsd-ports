--- plugins/layout/TreeReingoldAndTilfordExtended.cpp.orig	2007-12-18 21:56:53.000000000 +0100
+++ plugins/layout/TreeReingoldAndTilfordExtended.cpp	2007-12-18 22:01:13.000000000 +0100
@@ -21,8 +21,8 @@
   itG=arbreG.begin();
   itD=arbreD.begin();
   decal = ((*itG).R-(*itD).L + 1);
-  iG+=(*itG).size<?(*itD).size;
-  iD+=(*itG).size<?(*itD).size;
+  iG+= (itG->size < itD->size) ? itG->size : itD->size;
+  iD+= (itG->size < itD->size) ? itG->size : itD->size;
   if (iG==(*itG).size) {
     ++itG;iG=0;
   }
@@ -30,8 +30,8 @@
     ++itD;iD=0;
   }
   while ((itG!=arbreG.end()) && (itD!=arbreD.end())) {
-    decal=decal>?((*itG).R-((*itD).L)+1);
-    int min=((*itG).size-iG)<?((*itD).size-iD);
+    decal = (decal > (itG->R - itD->L + 1)) ? decal : (itG->R - itD->L + 1);
+    int min = ((itG->size - iG) < (itD->size - iD)) ? (itG->size - iG) : (itD->size - iD);
     iG+=min;
     iD+=min;
     if (iG==(*itG).size) {
@@ -54,7 +54,7 @@
   while((itL!=L->end()) && (itR!=R->end())) {
     tmp.L=(*itL).L;
     tmp.R=(*itR).R+decal;
-    int min=((*itL).size-iL)<?((*itR).size-iR);
+    int min = ((itL->size - iL) < (itR->size - iR)) ? itL->size - iL : itR->size - iR;
     tmp.size=min;
 
     if ((*itL).size==1) { //start
