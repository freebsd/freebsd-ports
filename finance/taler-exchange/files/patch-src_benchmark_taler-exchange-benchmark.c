--- src/benchmark/taler-exchange-benchmark.c.orig	2026-07-21 11:10:12 UTC
+++ src/benchmark/taler-exchange-benchmark.c
@@ -296,7 +296,7 @@ run (void *cls,
                                      GNUNET_TIME_UNIT_ZERO,
                                      amount_1,
                                      MHD_HTTP_OK));
-      if (eval_probability (refresh_rate / 100.0d))
+      if (eval_probability (refresh_rate / 100.0))
       {
         char *melt_label;
         char *reveal_label;
@@ -628,7 +628,7 @@ main (int argc,
              " * Reserve=%u * Parallel=%u, operations in %s\n",
              howmany_coins,
              howmany_coins,
-             howmany_coins * (refresh_rate / 100.0d),
+             howmany_coins * (refresh_rate / 100.0),
              howmany_reserves,
              howmany_clients,
              GNUNET_STRINGS_relative_time_to_string (
