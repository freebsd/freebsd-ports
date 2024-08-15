--- libs/pika/resource_partitioner/tests/unit/suspend_disabled.cpp.orig	2024-07-09 07:19:49 UTC
+++ libs/pika/resource_partitioner/tests/unit/suspend_disabled.cpp
@@ -43,8 +43,16 @@ int pika_main()
     return EXIT_SUCCESS;
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
     pika::init_params init_args;
 
     using ::pika::threads::scheduler_mode;
