--- src/Jackknife.cpp.orig	2019-08-03 00:15:27 UTC
+++ src/Jackknife.cpp
@@ -28,8 +28,8 @@ namespace Jackknife {
   using std::make_pair;
 
   double stddev(const vector <double> &x, int n) {
-    for (int i = 0; i < n; i++) if (isnan(x[i])) return NAN;
-    for (int i = 0; i < n; i++) if (isinf(x[i])) return INFINITY;
+    for (int i = 0; i < n; i++) if (std::isnan(x[i])) return NAN;
+    for (int i = 0; i < n; i++) if (std::isinf(x[i])) return INFINITY;
     double s = 0.0, s2 = 0.0;
     for (int i = 0; i < n; i++) {
       s += x[i];
