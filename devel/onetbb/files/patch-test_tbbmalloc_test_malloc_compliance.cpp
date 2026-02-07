Calling utils::LinuxKernelVersion() is only relevant on Linux

This fixes test 131:

131 - test_malloc_compliance (Subprocess aborted)

--- test/tbbmalloc/test_malloc_compliance.cpp.orig	2025-10-29 11:31:36 UTC
+++ test/tbbmalloc/test_malloc_compliance.cpp
@@ -1032,7 +1032,7 @@ TEST_CASE("MAIN TEST") {
     // Check if we were called to test standard behavior
     // TODO: enable this mode
     // setSystemAllocs();
-#if __unix__
+#if __linux__
     /* According to man pthreads
        "NPTL threads do not share resource limits (fixed in kernel 2.6.10)".
        Use per-threads limits for affected systems.
