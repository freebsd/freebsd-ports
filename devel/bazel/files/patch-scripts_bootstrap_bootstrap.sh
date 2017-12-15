--- scripts/bootstrap/bootstrap.sh.orig	2017-11-11 21:44:20 UTC
+++ scripts/bootstrap/bootstrap.sh
@@ -47,7 +47,7 @@ else
         --host_java_toolchain=//src/java_tools/buildjar:bootstrap_toolchain \
         --spawn_strategy=standalone \
         --nojava_header_compilation \
-        --strategy=Javac=worker --worker_quit_after_build --ignore_unsupported_sandboxing \
+        --strategy=Javac=standalone --ignore_unsupported_sandboxing --curses=no \
         --compilation_mode=opt \
         ${EXTRA_BAZEL_ARGS:-}"
 fi
