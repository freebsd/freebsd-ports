--- library/tulip/include/tulip/GraphIterator.h.orig	Mon Jan 20 04:19:54 2003
+++ library/tulip/include/tulip/GraphIterator.h	Fri Oct 29 14:14:08 2004
@@ -11,6 +11,7 @@
 #ifndef TULIP_GGRAPHITERATOR_H
 #define TULIP_GGRAPHITERATOR_H
 #include "Iterator.h"
+#include "SubGraph.h"
 #include "SuperGraph.h"
 #include "SuperGraphImpl.h"
 
@@ -26,7 +27,7 @@
 //typedef STL_EXT_NS::hash_map<node,std::pair< std::vector<edge> , std::vector<edge> > > nodesStruct;
 
 class SelectionProxy;
-class SubGraph;
+//class SubGraph;
 //template<class C>class Iterator;
 
 //===========================================================
