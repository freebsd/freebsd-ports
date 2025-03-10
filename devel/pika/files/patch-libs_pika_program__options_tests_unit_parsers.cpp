--- libs/pika/program_options/tests/unit/parsers.cpp.orig	2024-12-18 14:24:34 UTC
+++ libs/pika/program_options/tests/unit/parsers.cpp
@@ -13,6 +13,9 @@
 #include <pika/program_options/value_semantic.hpp>
 #include <pika/program_options/variables_map.hpp>
 #include <pika/testing.hpp>
+#if defined(__FreeBSD__)
+#  include <pika/debugging/environ.hpp>
+#endif
 
 #include <cstddef>
 #include <cstdlib>    // for putenv
@@ -325,6 +328,11 @@ int main()
 
 int main()
 {
+#if defined(__FreeBSD__)
+    extern char **environ;
+    freebsd_environ = environ;
+#endif
+
     test_command_line();
     test_environment();
     test_unregistered();
