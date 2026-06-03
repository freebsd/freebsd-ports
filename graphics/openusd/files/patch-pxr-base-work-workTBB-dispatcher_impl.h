--- pxr/base/work/workTBB/dispatcher_impl.h.orig	2026-05-13 12:42:10 UTC
+++ pxr/base/work/workTBB/dispatcher_impl.h
@@ -10,6 +10,7 @@
 #include "pxr/pxr.h"
 #include "pxr/base/work/api.h"
 
+#include <tbb/version.h>
 // Blocked range is not used in this file, but this header happens to pull in
 // the TBB version header in a way that works in all TBB versions.
 #include <tbb/blocked_range.h>
