--- adb/sysdeps_test.cpp.orig	2017-06-27 22:39:52 UTC
+++ adb/sysdeps_test.cpp
@@ -19,6 +19,7 @@
 
 #include <atomic>
 #include <condition_variable>
+#include <mutex>
 #include <thread>
 
 #include "adb_io.h"
