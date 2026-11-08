Don't overflow return value from main()

--- libs/stacktrace/build/has_addr2line.cpp.orig	2026-04-15 14:39:00 UTC
+++ libs/stacktrace/build/has_addr2line.cpp
@@ -10,13 +10,14 @@
 #include <unwind.h>
 #include <sys/types.h>
 #include <sys/wait.h>
+#include <unistd.h>
 
 int main() {
 
 #ifdef BOOST_STACKTRACE_ADDR2LINE_LOCATION
-    const char* s = BOOST_STRINGIZE( BOOST_STACKTRACE_ADDR2LINE_LOCATION ) " -h";
+    const char* s = BOOST_STRINGIZE( BOOST_STACKTRACE_ADDR2LINE_LOCATION );
 #else
-    const char* s = "/usr/bin/addr2line -h";
+    const char* s = "/usr/bin/addr2line";
 #endif
 
     return std::system(s);
