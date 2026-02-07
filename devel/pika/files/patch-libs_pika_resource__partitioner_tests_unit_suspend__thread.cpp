--- libs/pika/resource_partitioner/tests/unit/suspend_thread.cpp.orig	2025-01-18 02:20:05 UTC
+++ libs/pika/resource_partitioner/tests/unit/suspend_thread.cpp
@@ -215,6 +215,11 @@ int main(int argc, char* argv[])
 
 int main(int argc, char* argv[])
 {
+#if defined(__FreeBSD__)
+    extern char **environ;
+    freebsd_environ = environ;
+#endif
+
     PIKA_ASSERT(max_threads >= 2);
 
     // NOTE: Static schedulers do not support suspending the own worker thread
