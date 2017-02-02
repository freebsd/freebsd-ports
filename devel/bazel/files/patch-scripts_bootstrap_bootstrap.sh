--- scripts/bootstrap/bootstrap.sh.orig	1979-12-31 23:00:00 UTC
+++ scripts/bootstrap/bootstrap.sh
@@ -47,7 +47,7 @@ else
         --host_javabase=$JAVA_HOME \
         --spawn_strategy=standalone \
         --nojava_header_compilation \
-        --strategy=Javac=worker --worker_quit_after_build --ignore_unsupported_sandboxing \
+        --strategy=Javac=standalone --ignore_unsupported_sandboxing \
         --compilation_mode=opt \
         "${EXTRA_BAZEL_ARGS:-}"}
 fi
@@ -99,7 +99,7 @@ function bootstrap_test() {
   local BAZEL_BIN=$1
   local BAZEL_SUM=$2
   local BAZEL_TARGET=${3:-src:bazel}
-  local STRATEGY="--strategy=Javac=worker --worker_quit_after_build"
+  local STRATEGY="--strategy=Javac=standalone"
   if [ "${JAVA_VERSION}" = "1.7" ]; then
     STRATEGY=
   fi
