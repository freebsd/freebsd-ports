--- plugins/clustering/EqualValueClustering.cpp.orig	Wed Apr  2 15:57:11 2003
+++ plugins/clustering/EqualValueClustering.cpp	Fri Oct 29 14:14:16 2004
@@ -19,7 +19,7 @@
 {}
 
 namespace STL_EXT_NS {
-  struct hash<double> {
+  template <> struct hash<double> {
     size_t operator()(const double s) const { return (size_t)s; }
   };
 };
