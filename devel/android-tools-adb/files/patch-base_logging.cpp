--- base/logging.cpp.orig	2015-06-17 22:20:38 UTC
+++ base/logging.cpp
@@ -23,12 +23,14 @@
 #include <libgen.h>
 
 // For getprogname(3) or program_invocation_short_name.
-#if defined(__ANDROID__) || defined(__APPLE__)
+#if !defined(_WIN32) && !defined(__GLIBC__)
 #include <stdlib.h>
 #elif defined(__GLIBC__)
 #include <errno.h>
 #endif
 
+#include <cstring> // strlen
+#include <cstdio>  // fprintf
 #include <iostream>
 #include <limits>
 #include <sstream>
