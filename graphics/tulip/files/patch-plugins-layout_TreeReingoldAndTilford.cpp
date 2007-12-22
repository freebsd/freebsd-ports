--- plugins/layout/TreeReingoldAndTilford.cpp.orig	2007-12-18 21:50:08.000000000 +0100
+++ plugins/layout/TreeReingoldAndTilford.cpp	2007-12-18 21:56:13.000000000 +0100
@@ -20,8 +20,8 @@
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
@@ -29,8 +29,8 @@
     ++itD;iD=0;
   }
   while ((itG!=arbreG.end()) && (itD!=arbreD.end())) {
-    decal=decal>?((*itG).R-((*itD).L)+1);
-    int min=((*itG).size-iG)<?((*itD).size-iD);
+    decal = (decal > (itG->R - itD->L+1)) ? decal : (itG->R - itD->L+1);
+    int min= ((itG->size - iG) < (itD->size-iD)) ? (itG->size - iG) : (itD->size-iD);
     iG+=min;
     iD+=min;
     if (iG==(*itG).size) {
@@ -53,7 +53,7 @@
   while((itL!=L->end()) && (itR!=R->end())) {
     tmp.L=(*itL).L;
     tmp.R=(*itR).R+decal;
-    int min=((*itL).size-iL)<?((*itR).size-iR);
+    int min = ((itL->size-iL) < (itR->size-iR)) ? (itL->size-iL) : (itR->size-iR);
     tmp.size=min;
 
     if ((*itL).size==1) { //start
