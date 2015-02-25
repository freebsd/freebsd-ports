--- garbage_collector.cc.orig	2014-05-03 22:16:07.000000000 +0400
+++ garbage_collector.cc	2015-02-21 16:58:28.000000000 +0300
@@ -30,6 +30,8 @@
 // e
 #include "e/garbage_collector.h"
 
+#include <algorithm>
+
 using e::garbage_collector;
 
 class garbage_collector::thread_state_node
