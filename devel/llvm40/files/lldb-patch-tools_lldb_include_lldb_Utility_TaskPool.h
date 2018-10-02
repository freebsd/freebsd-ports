--- tools/lldb/include/lldb/Utility/TaskPool.h.orig	2018-09-20 19:31:12 UTC
+++ tools/lldb/include/lldb/Utility/TaskPool.h
@@ -33,6 +33,7 @@
 #include <queue>
 #include <thread>
 #include <vector>
+#include <functional>
 
 // Global TaskPool class for running tasks in parallel on a set of worker thread
 // created the first
