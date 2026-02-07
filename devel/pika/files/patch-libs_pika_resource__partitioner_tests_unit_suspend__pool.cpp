--- libs/pika/resource_partitioner/tests/unit/suspend_pool.cpp.orig	2025-01-18 02:04:11 UTC
+++ libs/pika/resource_partitioner/tests/unit/suspend_pool.cpp
@@ -157,6 +157,11 @@ int main(int argc, char* argv[])
 
 int main(int argc, char* argv[])
 {
+#if defined(__FreeBSD__)
+    extern char **environ;
+    freebsd_environ = environ;
+#endif
+
     PIKA_ASSERT(max_threads >= 2);
 
     std::vector<pika::resource::scheduling_policy> schedulers = {
