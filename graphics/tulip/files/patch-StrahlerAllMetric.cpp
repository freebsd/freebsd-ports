--- plugins/metric/StrahlerAllMetric.cpp.orig	Fri Dec  6 21:39:55 2002
+++ plugins/metric/StrahlerAllMetric.cpp	Fri Oct 29 14:14:17 2004
@@ -18,7 +18,7 @@
     }
   };
 
-  struct equal_to<couple>
+  template <> struct equal_to<couple>
   {
     bool operator()(const couple &c,const couple &d)
     {
@@ -27,7 +27,7 @@
     }
   };
 
-  struct less<couple>
+  template <> struct less<couple>
   {
     bool operator()(const couple &c,const couple &d)
     {
