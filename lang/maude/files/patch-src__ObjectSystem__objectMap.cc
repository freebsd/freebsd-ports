--- ./src/ObjectSystem/objectMap.cc.orig	2014-09-03 02:39:09.000000000 +0200
+++ ./src/ObjectSystem/objectMap.cc	2014-09-03 02:39:20.000000000 +0200
@@ -50,7 +50,7 @@
 
 struct ConfigSymbol::dagNodeLt
 {
-  bool operator()(const DagNode* d1, const DagNode* d2)
+  bool operator()(const DagNode* d1, const DagNode* d2) const
     {
       return d1->compare(d2) < 0;
     }
