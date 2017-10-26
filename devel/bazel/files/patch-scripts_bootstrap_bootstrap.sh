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
