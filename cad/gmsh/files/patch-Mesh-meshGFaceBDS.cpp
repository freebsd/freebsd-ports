--- Mesh/meshGFaceBDS.cpp.orig
+++ Mesh/meshGFaceBDS.cpp
@@ -771,8 +771,8 @@
   while (it != m.edges.end()){
     BDS_Edge *e = *it;
     if (!e->deleted && e->numfaces() == 2){
-      std::map<BDS_Point*, MVertex*>::iterator itp1 = recoverMap->find(e->p1);
-      std::map<BDS_Point*, MVertex*>::iterator itp2 = recoverMap->find(e->p2);
+      std::map<BDS_Point*, MVertex*, PointLessThan>::iterator itp1 = recoverMap->find(e->p1);
+      std::map<BDS_Point*, MVertex*, PointLessThan>::iterator itp2 = recoverMap->find(e->p2);
       if (itp1 != recoverMap->end() &&
           itp2 != recoverMap->end() &&
           itp1->second == itp2->second) toSplit.insert(e);
