--- libs/apto/utils/unittest/googletest/include/gtest/internal/gtest-port.h.orig	2012-09-29 03:33:39.000000000 +0000
+++ libs/apto/utils/unittest/googletest/include/gtest/internal/gtest-port.h
@@ -173,6 +173,7 @@
 #include <stdlib.h>
 #include <stdio.h>
 #include <string.h>
+#include <unistd.h>
 #ifndef _WIN32_WCE
 #include <sys/stat.h>
 #endif  // !_WIN32_WCE
