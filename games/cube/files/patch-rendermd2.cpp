--- rendermd2.cpp.orig	2015-02-14 01:31:41.354388000 +0100
+++ rendermd2.cpp	2015-02-14 01:39:38.592584000 +0100
@@ -234,7 +234,7 @@
 
 void mapmodelreset() { mapmodels.setsize(0); };
 
-mapmodelinfo &getmminfo(int i) { return i<mapmodels.length() ? mapmodels[i]->mmi : *(mapmodelinfo *)0; };
+mapmodelinfo *getmminfo(int i) { return i<mapmodels.length() ? &mapmodels[i]->mmi : 0; };
 
 COMMAND(mapmodel, ARG_5STR);
 COMMAND(mapmodelreset, ARG_NONE);
