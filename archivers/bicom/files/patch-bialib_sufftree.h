--- bialib/sufftree.h.orig	2000-10-26 01:51:04 UTC
+++ bialib/sufftree.h
@@ -95,7 +95,7 @@ class SuffixTreeModel : public Arithmeti
     {
     public:
     bool InEdge()
-      {return(r>0);}
+      {return(r!=NULL);}
     //After Canonize()ing a point, r >0 <=> proj!=0, i.e., point
     //is inside an edge
     INode *ins;  //parent of point
