--- plugins/selection/MultipleEdgeSelection.cpp.orig	Wed Apr  2 01:39:52 2003
+++ plugins/selection/MultipleEdgeSelection.cpp	Fri Oct 29 14:14:19 2004
@@ -29,7 +29,7 @@
 };
 
 namespace std {
-  struct less<edgeS> {
+  template <> struct less<edgeS> {
     bool operator()(const edgeS &c,const edgeS &d) const {
       if (c.source.id<d.source.id) return true;
       if (c.source.id>d.source.id) return false;
