--- src/libslic3r/utils.cpp.orig	2021-07-16 10:14:03 UTC
+++ src/libslic3r/utils.cpp
@@ -43,7 +43,7 @@
 #include <boost/nowide/convert.hpp>
 #include <boost/nowide/cstdio.hpp>
 
-#include <tbb/task_scheduler_init.h>
+#include <tbb/global_control.h>
 
 #if defined(__linux__) || defined(__GNUC__ )
 #include <strings.h>
@@ -118,9 +118,7 @@ void trace(unsigned int level, const char *message)
 void disable_multi_threading()
 {
     // Disable parallelization so the Shiny profiler works
-    static tbb::task_scheduler_init *tbb_init = nullptr;
-    if (tbb_init == nullptr)
-        tbb_init = new tbb::task_scheduler_init(1);
+    tbb::global_control(tbb::global_control::max_allowed_parallelism, 1);
 }
 
 static std::string g_var_dir;
