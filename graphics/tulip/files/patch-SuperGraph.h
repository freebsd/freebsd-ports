--- library/tulip/include/tulip/SuperGraph.h.orig	Tue Apr 29 16:37:58 2003
+++ library/tulip/include/tulip/SuperGraph.h	Fri Oct 29 14:14:08 2004
@@ -50,14 +50,14 @@
 };
 
 namespace STL_EXT_NS {
-struct hash<node>{size_t operator()(const node n) const {return n.id;}};
-struct hash<edge>{size_t operator()(const edge e) const {return e.id;}};
+template <> struct hash<node>{size_t operator()(const node n) const {return n.id;}};
+template <> struct hash<edge>{size_t operator()(const edge e) const {return e.id;}};
 }
 namespace std {
-struct equal_to<node>{size_t operator()(const node n,const node n2) const {return n.id==n2.id;}};
-struct equal_to<edge>{size_t operator()(const edge e,const edge e2) const {return e.id==e2.id;}};
-struct less<node>{size_t operator()(const node n,const node n2) const {return n.id<n2.id;}};
-struct less<edge>{size_t operator()(const edge e,const edge e2) const {return e.id<e2.id;}};
+template <> struct equal_to<node>{size_t operator()(const node n,const node n2) const {return n.id==n2.id;}};
+template <> struct equal_to<edge>{size_t operator()(const edge e,const edge e2) const {return e.id==e2.id;}};
+template <> struct less<node>{size_t operator()(const node n,const node n2) const {return n.id<n2.id;}};
+template <> struct less<edge>{size_t operator()(const edge e,const edge e2) const {return e.id<e2.id;}};
 }
 
 
