--- adb/adb_io_test.cpp.orig	2015-09-05 00:01:27 UTC
+++ adb/adb_io_test.cpp
@@ -18,6 +18,7 @@
 
 #include <gtest/gtest.h>
 
+#include <errno.h>
 #include <fcntl.h>
 #include <stdio.h>
 #include <stdlib.h>
