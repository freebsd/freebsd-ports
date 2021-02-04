--- testsuite/testsuite.sh.orig	2021-02-04 00:41:47 UTC
+++ testsuite/testsuite.sh
@@ -97,7 +97,7 @@ for opt; do
   esac
 done
 
-if [ "x$tests" = "x" ]; then tests="sanity pyunit gna vests synth vpi"; fi
+if [ "x$tests" = "x" ]; then tests="sanity gna vests synth vpi"; fi
 
 echo "> tests: $tests"
 echo "> args: $@"
