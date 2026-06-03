--- scripts/bootstrap/bootstrap.sh.orig	2020-10-07 21:26:37 UTC
+++ scripts/bootstrap/bootstrap.sh
@@ -33,7 +33,7 @@ fi
 
 _BAZEL_ARGS="--spawn_strategy=standalone \
       --nojava_header_compilation \
-      --strategy=Javac=worker --worker_quit_after_build --ignore_unsupported_sandboxing \
+      --strategy=Javac=standalone --ignore_unsupported_sandboxing --curses=no \
       --compilation_mode=opt \
       --distdir=derived/distdir \
       --java_toolchain=//src/java_tools/buildjar:bootstrap_toolchain \
