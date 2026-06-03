--- pxr/base/work/workTBB/detachedTask_impl.h.orig	2026-05-13 12:49:49 UTC
+++ pxr/base/work/workTBB/detachedTask_impl.h
@@ -11,6 +11,7 @@
 #include "pxr/base/work/workTBB/dispatcher_impl.h"
 #include "pxr/base/work/api.h"
 
+#include <tbb/version.h>
 #if TBB_INTERFACE_VERSION_MAJOR >= 12
 #include <tbb/task_group.h>
 #else
