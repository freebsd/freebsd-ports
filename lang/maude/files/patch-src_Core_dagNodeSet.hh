./dagNodeSet.hh:35:15: error: ISO C++11 does not allow access declarations; use using
      declarations instead
  PointerSet::cardinality;
              ^

--- src/Core/dagNodeSet.hh.orig	2018-08-27 20:49:56 UTC
+++ src/Core/dagNodeSet.hh
@@ -32,8 +32,8 @@ class DagNodeSet : private PointerSet
 public:
   int insert(DagNode* d);
   int dagNode2Index(DagNode* d) const;
-  PointerSet::cardinality;
-  PointerSet::makeEmpty;
+  using PointerSet::cardinality;
+  using PointerSet::makeEmpty;
   DagNode* index2DagNode(int i) const;
 
 private:
