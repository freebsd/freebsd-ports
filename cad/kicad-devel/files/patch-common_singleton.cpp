--- common/singleton.cpp.orig	2026-06-23 12:53:54 UTC
+++ common/singleton.cpp
@@ -59,13 +59,7 @@ void KICAD_SINGLETON::Init()
 {
     int num_threads = std::max( 0, ADVANCED_CFG::GetCfg().m_MaximumThreads );
 
-    m_ThreadPool = new BS::priority_thread_pool( num_threads,
-                                                 []
-                                                 {
-                                                     // Reduce worker threadpriority to reduce lag in main (UI) thread
-                                                     BS::this_thread::set_os_thread_priority(
-                                                             BS::os_thread_priority::below_normal );
-                                                 } );
+    m_ThreadPool = new BS::priority_thread_pool( num_threads );
 
     m_GLContextManager = new GL_CONTEXT_MANAGER();
 }
