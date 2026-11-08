--- benchmark/runtime/float/single.cpp.orig	2024-11-03 23:00:07 UTC
+++ benchmark/runtime/float/single.cpp
@@ -185,4 +185,3 @@ BENCHMARK_TEMPLATE(scan_float_single_fastfloat, double
 }
 BENCHMARK_TEMPLATE(scan_float_single_fastfloat, float);
 BENCHMARK_TEMPLATE(scan_float_single_fastfloat, double);
-BENCHMARK_TEMPLATE(scan_float_single_fastfloat, long double);
