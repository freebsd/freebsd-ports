--- scripts/bootstrap/bootstrap.sh.orig	1979-12-31 23:00:00 UTC
+++ scripts/bootstrap/bootstrap.sh
@@ -39,7 +39,7 @@ if [ "${JAVA_VERSION}" = "1.7" ]; then
 else
   : ${BAZEL_ARGS:=--java_toolchain=//src/java_tools/buildjar:bootstrap_toolchain \
         --host_java_toolchain=//src/java_tools/buildjar:bootstrap_toolchain \
-        --strategy=Javac=worker --worker_quit_after_build --ignore_unsupported_sandboxing \
+        --strategy=Javac=standalone --ignore_unsupported_sandboxing \
         --compilation_mode=opt \
         "${EXTRA_BAZEL_ARGS:-}"}
 fi
@@ -91,7 +91,7 @@ function bootstrap_test() {
   local BAZEL_BIN=$1
   local BAZEL_SUM=$2
   local BAZEL_TARGET=${3:-src:bazel}
-  local STRATEGY="--strategy=Javac=worker --worker_quit_after_build"
+  local STRATEGY="--strategy=Javac=standalone"
   if [ "${JAVA_VERSION}" = "1.7" ]; then
     STRATEGY=
   fi
