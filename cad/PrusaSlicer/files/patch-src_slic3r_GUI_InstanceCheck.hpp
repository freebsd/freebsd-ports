--- src/slic3r/GUI/InstanceCheck.hpp.orig	2021-07-16 10:14:03 UTC
+++ src/slic3r/GUI/InstanceCheck.hpp
@@ -13,7 +13,7 @@
 
 #if __linux__
 #include <boost/thread.hpp>
-#include <tbb/mutex.h>
+#include <mutex>
 #include <condition_variable>
 #endif // __linux__
 
