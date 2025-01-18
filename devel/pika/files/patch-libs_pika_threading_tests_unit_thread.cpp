--- libs/pika/threading/tests/unit/thread.cpp.orig	2025-01-18 01:55:17 UTC
+++ libs/pika/threading/tests/unit/thread.cpp
@@ -362,6 +362,11 @@ int main(int argc, char* argv[])
 ///////////////////////////////////////////////////////////////////////////////
 int main(int argc, char* argv[])
 {
+#if defined(__FreeBSD__)
+    extern char **environ;
+    freebsd_environ = environ;
+#endif
+
     // Configure application-specific options
     options_description cmdline("Usage: " PIKA_APPLICATION_STRING " [options]");
 
