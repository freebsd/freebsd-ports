--- libs/pika/resource_partitioner/tests/unit/shutdown_suspended_pus.cpp.orig	2024-07-09 07:28:43 UTC
+++ libs/pika/resource_partitioner/tests/unit/shutdown_suspended_pus.cpp
@@ -75,8 +75,16 @@ void test_scheduler(int argc, char* argv[], pika::reso
     PIKA_TEST_EQ(pika::init(pika_main, argc, argv, init_args), 0);
 }
 
+#if defined(__FreeBSD__)
+extern char **environ;
+#endif
+
 int main(int argc, char* argv[])
 {
+#if defined(__FreeBSD__)
+    freebsd_environ = environ;
+#endif
+
     PIKA_ASSERT(max_threads >= 2);
 
     {
