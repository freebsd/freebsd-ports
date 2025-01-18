--- tests/regressions/unhandled_exception_582.cpp.orig	2025-01-18 02:01:28 UTC
+++ tests/regressions/unhandled_exception_582.cpp
@@ -21,6 +21,11 @@ int main(int argc, char** argv)
 
 int main(int argc, char** argv)
 {
+#if defined(__FreeBSD__)
+    extern char **environ;
+    freebsd_environ = environ;
+#endif
+
     bool caught_exception = false;
     try
     {
