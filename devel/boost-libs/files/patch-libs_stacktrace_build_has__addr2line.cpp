Don't overflow return value from main()

--- libs/stacktrace/build/has_addr2line.cpp.orig	2017-07-10 14:19:05 UTC
+++ libs/stacktrace/build/has_addr2line.cpp
@@ -4,22 +4,24 @@
 // accompanying file LICENSE_1_0.txt or copy at
 // http://www.boost.org/LICENSE_1_0.txt)
 
-#include <cstdlib>
 #include <string>
 
 #include <boost/config.hpp>
-#include <unwind.h>
-#include <sys/types.h>
-#include <sys/wait.h>
+#ifdef BOOST_MSVC
+#include <io.h>
+#define X_OK 4
+#define access _access
+#else
+#include <unistd.h>
+#endif
 
 int main() {
 
 #ifdef BOOST_STACKTRACE_ADDR2LINE_LOCATION
     std::string s = BOOST_STRINGIZE( BOOST_STACKTRACE_ADDR2LINE_LOCATION );
-    s += " -h";
 #else
-    std::string s = "/usr/bin/addr2line -h";
+    std::string s = "/usr/bin/addr2line";
 #endif
 
-    return std::system(s.c_str());
+    return ::access(s.c_str(), X_OK) == -1;
 }
