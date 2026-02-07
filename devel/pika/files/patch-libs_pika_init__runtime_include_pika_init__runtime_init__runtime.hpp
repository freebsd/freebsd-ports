- hack to work around https://github.com/pika-org/pika/issues/649

--- libs/pika/init_runtime/include/pika/init_runtime/init_runtime.hpp.orig	2023-12-06 08:42:57 UTC
+++ libs/pika/init_runtime/include/pika/init_runtime/init_runtime.hpp
@@ -44,6 +44,7 @@
 
 #if defined(__FreeBSD__)
 extern PIKA_EXPORT char** freebsd_environ;
+#else
 extern char** environ;
 #endif
 
