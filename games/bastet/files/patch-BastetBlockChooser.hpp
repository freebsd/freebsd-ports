--- BastetBlockChooser.hpp.orig	2009-03-21 06:49:31.000000000 +0900
+++ BastetBlockChooser.hpp	2013-11-29 22:35:48.000000000 +0900
@@ -23,19 +23,32 @@
 
 #include "Well.hpp"
 
+#if !defined(_LIBCPP_VERSION)
 #include <tr1/unordered_set>
+#else
+#include <unordered_set>
+#endif
 #include <set>
 #include <boost/functional/hash.hpp>
 
+#if !defined(_LIBCPP_VERSION)
 //boilerplate to use boost::hash as std::tr1::hash
 namespace std{namespace tr1{
+#else
+//boilerplate to use boost::hash as std::hash
+namespace std{
+#endif
     template<> struct hash<Bastet::BlockPosition>{
       size_t operator()(const Bastet::BlockPosition &fb) const{
 	static boost::hash<Bastet::BlockPosition> h;
 	return h(fb);
       }
     };
+#if !defined(_LIBCPP_VERSION)
   }}
+#else
+  }
+#endif
 
 namespace Bastet{
 
@@ -83,7 +96,11 @@
   public:
     Searcher(BlockType b, const Well *well, Vertex v, WellVisitor *visitor);
   private:
+#if !defined(_LIBCPP_VERSION)
     std::tr1::unordered_set<Vertex> _visited;
+#else
+    std::unordered_set<Vertex> _visited;
+#endif
     //std::set<Vertex> _visited; ^^ the above is more efficient, we need to do many inserts
     BlockType _block;
     const Well *_well;
