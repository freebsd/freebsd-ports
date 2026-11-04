--- tests/doctest/test_debugger.cpp.orig	2026-07-06 21:58:29 UTC
+++ tests/doctest/test_debugger.cpp
@@ -3,7 +3,7 @@
 #if defined(DOCTEST_PLATFORM_WINDOWS)
 #include <doctest/parts/private/ext/windows.h>
 
-#elif defined(DOCTEST_PLATFORM_LINUX)
+#elif defined(DOCTEST_PLATFORM_LINUX) || defined(DOCTEST_PLATFORM_FREEBSD)
 #include <csignal>
 
 #else
@@ -39,7 +39,7 @@ inline void setup() {
     REQUIRE(handle == nullptr);
     handle = AddVectoredExceptionHandler(1, veh);
 
-#elif defined(DOCTEST_PLATFORM_LINUX)
+#elif defined(DOCTEST_PLATFORM_LINUX) || defined(DOCTEST_PLATFORM_FREEBSD)
     DOCTEST_CLANG_SUPPRESS_WARNING_WITH_PUSH("-Wdisabled-macro-expansion") /* sa_handler is a self-referential macro */
     struct sigaction sa = {};
     sa.sa_handler = [](int) { signal_caught = true; };
@@ -56,7 +56,7 @@ inline void cleanup() {
         RemoveVectoredExceptionHandler(handle);
         handle = nullptr;
     }
-#elif defined(DOCTEST_PLATFORM_LINUX)
+#elif defined(DOCTEST_PLATFORM_LINUX) || defined(DOCTEST_PLATFORM_FREEBSD)
 #if DOCTEST_CLANG >= DOCTEST_COMPILER(5, 0, 0)
     DOCTEST_CLANG_SUPPRESS_WARNING_WITH_PUSH(
         "-Wzero-as-null-pointer-constant"
