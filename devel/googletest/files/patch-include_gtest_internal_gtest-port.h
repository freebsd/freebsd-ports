--- include/gtest/internal/gtest-port.h.orig	2010-04-16 06:02:02.000000000 +0800
+++ include/gtest/internal/gtest-port.h	2013-10-16 23:39:02.000000000 +0800
@@ -173,6 +173,7 @@
 #include <stdlib.h>
 #include <stdio.h>
 #include <string.h>
+#include <unistd.h>
 #ifndef _WIN32_WCE
 #include <sys/stat.h>
 #endif  // !_WIN32_WCE
@@ -399,7 +400,7 @@
 // defining __GNUC__ and friends, but cannot compile GCC's tuple
 // implementation.  MSVC 2008 (9.0) provides TR1 tuple in a 323 MB
 // Feature Pack download, which we cannot assume the user has.
-#if (defined(__GNUC__) && !defined(__CUDACC__) && (GTEST_GCC_VER_ >= 40000)) \
+#if (defined(__GNUC__) && !defined(__CUDACC__) && !defined(_LIBCPP_VERSION) && (GTEST_GCC_VER_ >= 40000)) \
     || _MSC_VER >= 1600
 #define GTEST_USE_OWN_TR1_TUPLE 0
 #else
