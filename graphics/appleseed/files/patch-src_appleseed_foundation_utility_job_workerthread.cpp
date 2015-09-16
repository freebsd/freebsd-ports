--- src/appleseed/foundation/utility/job/workerthread.cpp.orig	2015-06-13 09:38:53 UTC
+++ src/appleseed/foundation/utility/job/workerthread.cpp
@@ -80,7 +80,7 @@ void WorkerThread::start()
     assert(!m_abort_switch.is_aborted());
 
     // Start the thread.
-    m_thread = new thread(m_thread_func);
+    m_thread = new boost::thread(m_thread_func);
 }
 
 void WorkerThread::stop()
@@ -110,7 +110,7 @@ void WorkerThread::pause()
     if (!m_thread)
         return;
 
-    mutex::scoped_lock lock(m_pause_mutex);
+    boost::mutex::scoped_lock lock(m_pause_mutex);
     m_pause_flag.set();
 }
 
@@ -120,7 +120,7 @@ void WorkerThread::resume()
     if (!m_thread)
         return;
 
-    mutex::scoped_lock lock(m_pause_mutex);
+    boost::mutex::scoped_lock lock(m_pause_mutex);
     m_pause_flag.clear();
     m_pause_event.notify_all();
 }
@@ -141,7 +141,7 @@ void WorkerThread::run()
         if (m_pause_flag.is_set())
         {
             // Wait until the resume event.
-            mutex::scoped_lock lock(m_pause_mutex);
+            boost::mutex::scoped_lock lock(m_pause_mutex);
             while (m_pause_flag.is_set())
                 m_pause_event.wait(lock);
         }
