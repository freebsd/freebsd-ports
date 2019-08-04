--- src/StatsUtils.cpp.orig	2019-08-03 00:24:37 UTC
+++ src/StatsUtils.cpp
@@ -33,8 +33,8 @@ namespace StatsUtils {
     if (n <= 1) return NAN;
     double s = 0.0, s2 = 0.0;
     for (uint64 i = 0; i < n; i++) {
-      if (isnan(x[i])) return NAN;
-      if (isinf(x[i])) return INFINITY;
+      if (std::isnan(x[i])) return NAN;
+      if (std::isinf(x[i])) return INFINITY;
       s += x[i];
       s2 += x[i]*x[i];
     }
