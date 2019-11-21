--- BastetBlockChooser.hpp.orig	2015-08-30 07:04:24 UTC
+++ BastetBlockChooser.hpp
@@ -23,7 +23,7 @@
 
 #include "Well.hpp"
 
-#include <boost/tr1/tr1/unordered_set>
+#include <boost/unordered_set.hpp>
 #include <set>
 #include <boost/functional/hash.hpp>
 
@@ -75,7 +75,7 @@ namespace Bastet{
   public:
     Searcher(BlockType b, const Well *well, Vertex v, WellVisitor *visitor);
   private:
-    std::tr1::unordered_set<Vertex> _visited;
+    boost::unordered_set<Vertex> _visited;
     //std::set<Vertex> _visited; ^^ the above is more efficient, we need to do many inserts
     BlockType _block;
     const Well *_well;
