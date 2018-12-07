--- src/bench/graphene-bench-utils.c.orig	2018-12-04 11:34:21 UTC
+++ src/bench/graphene-bench-utils.c
@@ -271,7 +271,7 @@ graphene_bench_print_results (const char *impl,
 {
   const char *d_unit, *round_unit, *iter_unit;
   double d = format_time (elapsed, &d_unit);
-  double round = format_time (avg, &round_unit);
+  double my_round = format_time (avg, &round_unit);
   double iter = format_time (avg / bench_unit_rounds, &iter_unit);
 
   switch (bench_output)
@@ -283,7 +283,7 @@ graphene_bench_print_results (const char *impl,
                " Per iteration: %.6f %s\n",
                path, (gint64) (num_rounds * bench_unit_rounds), impl,
                d, d_unit, num_rounds,
-               round, round_unit, bench_unit_rounds,
+               my_round, round_unit, bench_unit_rounds,
                iter, iter_unit);
       break;
 
