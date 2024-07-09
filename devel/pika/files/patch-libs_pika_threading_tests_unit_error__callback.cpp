--- libs/pika/threading/tests/unit/error_callback.cpp.orig	2024-07-09 07:16:05 UTC
+++ libs/pika/threading/tests/unit/error_callback.cpp
@@ -30,8 +30,16 @@ int pika_main()
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
     auto on_stop = pika::detail::register_thread_on_error_func(&on_thread_error);
     PIKA_TEST(on_stop.empty());
 
