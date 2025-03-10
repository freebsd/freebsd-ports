--- libs/pika/debugging/tests/unit/print.cpp.orig	2024-12-18 14:24:34 UTC
+++ libs/pika/debugging/tests/unit/print.cpp
@@ -12,6 +12,9 @@
 #include <pika/modules/timing.hpp>
 #include <pika/testing.hpp>
 #include <pika/threading_base/print.hpp>
+#if defined(__FreeBSD__)
+#  include <pika/debugging/environ.hpp>
+#endif
 
 #include <atomic>
 #include <chrono>
@@ -29,6 +32,11 @@ int main()
 
 int main()
 {
+#if defined(__FreeBSD__)
+    extern char **environ;
+    freebsd_environ = environ;
+#endif
+
     // some counters we will use for checking if anything happens or not
     std::atomic<int> enabled_counter(0);
     std::atomic<int> disabled_counter(0);
