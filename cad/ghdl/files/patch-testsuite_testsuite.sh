- PyGHDL should be in a separate port

--- testsuite/testsuite.sh.orig	2023-02-23 20:12:21 UTC
+++ testsuite/testsuite.sh
@@ -110,7 +110,7 @@ for opt; do
   esac
 done
 
-if [ "x$tests" = "x" ]; then tests="sanity pyunit gna vests synth vpi vhpi"; fi
+if [ "x$tests" = "x" ]; then tests="sanity        gna vests synth vpi vhpi"; fi
 
 echo "> tests: $tests"
 echo "> args: $@"
