--- ./utils/workqueue.h.orig	2013-09-30 18:45:06.000000000 +0200
+++ ./utils/workqueue.h	2013-10-29 15:57:51.000000000 +0100
@@ -22,10 +22,7 @@
 
 #include <string>
 #include <queue>
-#include <tr1/unordered_map>
-#include <tr1/unordered_set>
-using std::tr1::unordered_map;
-using std::tr1::unordered_set;
+#include "unordered_defs.h"
 using std::queue;
 using std::string;
 
@@ -216,7 +213,7 @@
 	// Perform the thread joins and compute overall status
         // Workers return (void*)1 if ok
         void *statusall = (void*)1;
-        unordered_map<pthread_t,  WQTData>::iterator it;
+        STD_UNORDERED_MAP<pthread_t,  WQTData>::iterator it;
         while (!m_worker_threads.empty()) {
             void *status;
             it = m_worker_threads.begin();
@@ -333,7 +330,7 @@
 
     // Per-thread data. The data is not used currently, this could be
     // a set<pthread_t>
-    unordered_map<pthread_t, WQTData> m_worker_threads;
+    STD_UNORDERED_MAP<pthread_t, WQTData> m_worker_threads;
 
     // Synchronization
     queue<T> m_queue;
