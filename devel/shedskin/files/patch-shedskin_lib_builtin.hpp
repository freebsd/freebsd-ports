-- workaround for https://github.com/shedskin/shedskin/issues/1244

--- shedskin/lib/builtin.hpp.orig	2026-09-17 22:47:48 UTC
+++ shedskin/lib/builtin.hpp
@@ -3,6 +3,10 @@
 #ifndef SS_BUILTIN_HPP
 #define SS_BUILTIN_HPP
 
+#include <sys/time.h>
+#include <unistd.h>
+#include <sys/stat.h>
+
 #ifdef __SS_BIND
 #include <Python.h>
 #endif
