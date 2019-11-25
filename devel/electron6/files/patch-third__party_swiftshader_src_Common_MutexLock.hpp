--- third_party/swiftshader/src/Common/MutexLock.hpp.orig	2019-09-10 10:47:39 UTC
+++ third_party/swiftshader/src/Common/MutexLock.hpp
@@ -17,7 +17,7 @@
 
 #include "Thread.hpp"
 
-#if defined(__linux__)
+#if defined(__linux__) || defined(__FreeBSD__)
 // Use a pthread mutex on Linux. Since many processes may use SwiftShader
 // at the same time it's best to just have the scheduler overhead.
 #include <pthread.h>
