--- test/functests/test_exclude_mono.sh.orig	2016-06-27 06:54:00 UTC
+++ test/functests/test_exclude_mono.sh
@@ -65,7 +65,7 @@ get_monotonic_time()
     dont_fake_mono=$1; shift;
     clock_id=$1; shift;
     DONT_FAKE_MONOTONIC=${dont_fake_mono} fakecmd "2014-07-21 09:00:00" \
-    /bin/bash -c "for i in 1 2; do \
+    /usr/bin/env bash -c "for i in 1 2; do \
     perl -w -MTime::HiRes=clock_gettime,${clock_id} -E \
     'say clock_gettime(${clock_id})'; \
     sleep 1; \
