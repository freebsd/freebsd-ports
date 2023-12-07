--- libs/pika/init_runtime/src/init_runtime.cpp.orig	2023-12-07 06:48:45 UTC
+++ libs/pika/init_runtime/src/init_runtime.cpp
@@ -355,7 +359,7 @@ namespace pika {
             }
 
 #if defined(__FreeBSD__)
-            freebsd_environ = environ;
+            //freebsd_environ = environ;
 #endif
             // set a handler for std::abort
             [[maybe_unused]] auto signal_handler = std::signal(SIGABRT, pika::detail::on_abort);
