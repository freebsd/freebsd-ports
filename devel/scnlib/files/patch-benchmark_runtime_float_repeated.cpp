--- benchmark/runtime/float/repeated.cpp.orig	2024-11-03 23:00:07 UTC
+++ benchmark/runtime/float/repeated.cpp
@@ -210,4 +210,3 @@ BENCHMARK_TEMPLATE(scan_float_repeated_fastfloat, doub
 }
 BENCHMARK_TEMPLATE(scan_float_repeated_fastfloat, float);
 BENCHMARK_TEMPLATE(scan_float_repeated_fastfloat, double);
-BENCHMARK_TEMPLATE(scan_float_repeated_fastfloat, long double);
