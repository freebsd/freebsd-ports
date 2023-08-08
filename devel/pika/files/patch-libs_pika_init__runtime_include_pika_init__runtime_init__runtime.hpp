- hack to work around https://github.com/pika-org/pika/issues/649

--- libs/pika/init_runtime/include/pika/init_runtime/init_runtime.hpp.orig	2023-04-10 00:11:12 UTC
+++ libs/pika/init_runtime/include/pika/init_runtime/init_runtime.hpp
@@ -44,6 +44,7 @@
 
 #if defined(__FreeBSD__)
 extern PIKA_EXPORT char** freebsd_environ;
+#else
 extern char** environ;
 #endif
 
@@ -113,7 +114,7 @@ namespace pika {
             }
 
 #if defined(__FreeBSD__)
-            freebsd_environ = environ;
+            //freebsd_environ = environ;
 #endif
             // set a handler for std::abort
             std::signal(SIGABRT, pika::detail::on_abort);
