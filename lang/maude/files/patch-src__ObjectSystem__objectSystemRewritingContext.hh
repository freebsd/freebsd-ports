--- ./src/ObjectSystem/objectSystemRewritingContext.hh.orig	2014-09-03 02:40:31.000000000 +0200
+++ ./src/ObjectSystem/objectSystemRewritingContext.hh	2014-09-03 02:40:48.000000000 +0200
@@ -62,7 +62,7 @@
 private:
   struct dagNodeLt
   {
-    bool operator()(const DagNode* d1, const DagNode* d2)
+    bool operator()(const DagNode* d1, const DagNode* d2) const
     {
       return d1->compare(d2) < 0;
     }
