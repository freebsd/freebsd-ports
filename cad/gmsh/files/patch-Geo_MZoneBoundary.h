--- Geo/MZoneBoundary.h-orig	2010-10-15 13:35:00.000000000 +0000
+++ Geo/MZoneBoundary.h	2011-07-25 03:22:05.000000000 +0000
@@ -317,12 +317,12 @@
   {
     // NBN: using FaceT* so need to dealloc:
     int icount = 0;
-    GlobalBoVertexMap::iterator itEnd = globalBoVertMap.end();
-    for (GlobalBoVertexMap::iterator itBoV = globalBoVertMap.begin(); 
+    typename GlobalBoVertexMap::iterator itEnd = globalBoVertMap.end();
+    for (typename GlobalBoVertexMap::iterator itBoV = globalBoVertMap.begin(); 
           itBoV != itEnd; ++itBoV)
     {
       // ... clear the faces
-      typename GlobalVertexData<FaceT>& ref = itBoV->second;
+      GlobalVertexData<FaceT>& ref = itBoV->second;
       size_t nf = ref.faces.size();
       for (int i=0; i<nf; ++i) {
         ++ icount;
