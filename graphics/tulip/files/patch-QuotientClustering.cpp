--- plugins/clustering/QuotientClustering.cpp.orig	Wed Apr  2 01:33:06 2003
+++ plugins/clustering/QuotientClustering.cpp	Fri Oct 29 14:14:16 2004
@@ -20,7 +20,7 @@
 };
 
 namespace std {
-  struct less<edgeS> {
+  template <> struct less<edgeS> {
     bool operator()(const edgeS &c,const edgeS &d) const {
       if (c.source<d.source) return true;
       if (c.source>d.source) return false;
@@ -36,7 +36,7 @@
 QuotientClustering::~QuotientClustering(){}
 
 namespace STL_EXT_NS {
-  struct hash<double> {
+  template <> struct hash<double> {
     size_t operator()(const double s) const { return (size_t)s; }
   };
 };
