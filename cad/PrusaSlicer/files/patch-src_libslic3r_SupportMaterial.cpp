--- src/libslic3r/SupportMaterial.cpp.orig	2021-07-16 10:14:03 UTC
+++ src/libslic3r/SupportMaterial.cpp
@@ -12,7 +12,6 @@
 #include <boost/log/trivial.hpp>
 
 #include <tbb/parallel_for.h>
-#include <tbb/atomic.h>
 #include <tbb/spin_mutex.h>
 #include <tbb/task_group.h>
 
