--- opensubdiv/osd/tbbEvaluator.cpp.orig	2021-12-17 16:59:23 UTC
+++ opensubdiv/osd/tbbEvaluator.cpp
@@ -25,7 +25,8 @@
 #include "../osd/tbbEvaluator.h"
 #include "../osd/tbbKernel.h"
 
-#include <tbb/task_scheduler_init.h>
+#define TBB_PREVIEW_GLOBAL_CONTROL true
+#include <tbb/global_control.h>
 
 namespace OpenSubdiv {
 namespace OPENSUBDIV_VERSION {
@@ -215,10 +216,11 @@ TbbEvaluator::Synchronize(void *) {
 /* static */
 void
 TbbEvaluator::SetNumThreads(int numThreads) {
-    if (numThreads == -1) {
-        tbb::task_scheduler_init init;
-    } else {
-        tbb::task_scheduler_init init(numThreads);
+    if (numThreads != -1) {
+        tbb::global_control tbb_global_control(
+            tbb::global_control::max_allowed_parallelism,
+            numThreads
+            );
     }
 }
 
