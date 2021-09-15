--- src/libslic3r/pchheader.hpp.orig	2021-07-16 10:14:03 UTC
+++ src/libslic3r/pchheader.hpp
@@ -93,12 +93,9 @@
 #include <boost/thread.hpp>
 #include <boost/version.hpp>
 
-#include <tbb/atomic.h>
 #include <tbb/parallel_for.h>
 #include <tbb/spin_mutex.h>
-#include <tbb/mutex.h>
 #include <tbb/task_group.h>
-#include <tbb/task_scheduler_init.h>
 
 #include <Eigen/Dense>
 #include <Eigen/Geometry>
