--- src/slic3r/GUI/Mouse3DController.hpp.orig	2021-07-16 10:14:03 UTC
+++ src/slic3r/GUI/Mouse3DController.hpp
@@ -10,12 +10,12 @@
 
 #include <queue>
 #include <atomic>
+#include <mutex>
 #include <thread>
 #include <vector>
 #include <chrono>
 #include <condition_variable>
 
-#include <tbb/mutex.h>
 
 namespace Slic3r {
 
@@ -85,7 +85,7 @@ class Mouse3DController
     	// m_input_queue is accessed by the background thread and by the UI thread. Access to m_input_queue
     	// is guarded with m_input_queue_mutex.
         std::deque<QueueItem> m_input_queue;
-        mutable tbb::mutex	  m_input_queue_mutex;
+        mutable std::mutex	  m_input_queue_mutex;
 
 #ifdef WIN32
         // When the 3Dconnexion driver is running the system gets, by default, mouse wheel events when rotations around the X axis are detected.
@@ -112,12 +112,12 @@ class Mouse3DController
 
 #if ENABLE_3DCONNEXION_DEVICES_DEBUG_OUTPUT
         Vec3d               get_first_vector_of_type(unsigned int type) const {
-            tbb::mutex::scoped_lock lock(m_input_queue_mutex);
+            std::scoped_lock<std::mutex> lock(m_input_queue_mutex);
             auto it = std::find_if(m_input_queue.begin(), m_input_queue.end(), [type](const QueueItem& item) { return item.type_or_buttons == type; });
             return (it == m_input_queue.end()) ? Vec3d::Zero() : it->vector;
         }
         size_t              input_queue_size_current() const { 
-        	tbb::mutex::scoped_lock lock(m_input_queue_mutex); 
+        	std::scoped_lock<std::mutex> lock(m_input_queue_mutex); 
         	return m_input_queue.size(); 
         }
         std::atomic<size_t> input_queue_max_size_achieved;
@@ -133,7 +133,7 @@ class Mouse3DController
     // UI thread will read / write this copy.
     Params 				m_params_ui;
     bool 	            m_params_ui_changed { false };
-    mutable tbb::mutex	m_params_ui_mutex;
+    mutable std::mutex	m_params_ui_mutex;
 
     // This is a database of parametes of all 3DConnexion devices ever connected.
     // This database is loaded from AppConfig on application start and it is stored to AppConfig on application exit.
