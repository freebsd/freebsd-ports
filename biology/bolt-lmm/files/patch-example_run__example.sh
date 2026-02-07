--- example/run_example.sh.orig	2017-11-11 16:45:05 UTC
+++ example/run_example.sh
@@ -1,4 +1,6 @@
-../bolt \
+#!/bin/sh -e
+
+bolt \
     --bfile=EUR_subset \
     --remove=EUR_subset.remove \
     --exclude=EUR_subset.exclude \
