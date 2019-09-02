--- scripts/bootstrap/bootstrap.sh.orig	2019-08-06 08:04:56.534744000 +0000
+++ scripts/bootstrap/bootstrap.sh	2019-08-06 08:05:20.598434000 +0000
@@ -35,7 +35,7 @@
       --host_java_toolchain=//src/java_tools/buildjar:bootstrap_toolchain \
       --spawn_strategy=standalone \
       --nojava_header_compilation \
-      --strategy=Javac=worker --worker_quit_after_build --ignore_unsupported_sandboxing \
+      --strategy=Javac=standalone --ignore_unsupported_sandboxing --curses=no \
       --compilation_mode=opt \
       --distdir=derived/distdir \
       ${EXTRA_BAZEL_ARGS:-}"
