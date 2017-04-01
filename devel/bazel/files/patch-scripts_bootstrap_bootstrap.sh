--- scripts/bootstrap/bootstrap.sh.orig	2017-03-07 08:07:48 UTC
+++ scripts/bootstrap/bootstrap.sh
@@ -43,7 +43,7 @@ else
         --host_java_toolchain=//src/java_tools/buildjar:bootstrap_toolchain \
         --spawn_strategy=standalone \
         --nojava_header_compilation \
-        --strategy=Javac=worker --worker_quit_after_build --ignore_unsupported_sandboxing \
+        --strategy=Javac=standalone --ignore_unsupported_sandboxing \
         --compilation_mode=opt \
         ${EXTRA_BAZEL_ARGS:-}"
 fi
@@ -96,7 +96,7 @@ function bootstrap_test() {
   local BAZEL_BIN=$1
   local BAZEL_SUM=$2
   local BAZEL_TARGET=${3:-src:bazel}
-  local STRATEGY="--strategy=Javac=worker --worker_quit_after_build"
+  local STRATEGY="--strategy=Javac=standalone"
   if [ "${JAVA_VERSION}" = "1.7" ]; then
     STRATEGY=
   fi
