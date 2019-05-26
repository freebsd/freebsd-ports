--- example/run_example_reml2.sh.orig	2018-03-10 19:39:24 UTC
+++ example/run_example_reml2.sh
@@ -1,4 +1,6 @@
-../bolt \
+#!/bin/sh -e
+
+bolt \
     --bfile=EUR_subset \
     --phenoFile=EUR_subset.pheno2.covars \
     --exclude=EUR_subset.exclude2 \
