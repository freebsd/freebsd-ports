--- plugins/metric/StrahlerMetric.cpp.orig	Fri Dec  6 21:39:55 2002
+++ plugins/metric/StrahlerMetric.cpp	Fri Oct 29 14:14:17 2004
@@ -27,7 +27,7 @@
     }
   };
 
-  struct equal_to<couple> {
+  template <> struct equal_to<couple> {
     bool operator()(const couple &c,const couple &d)
     {
       if ((c.r==d.r) && (c.p==d.p)) return true;
@@ -35,7 +35,7 @@
     }
   };
 
-  struct less<couple>
+  template <> struct less<couple>
   {
     bool operator()(const couple &c,const couple &d) {
       if (c.r<d.r) return true;
