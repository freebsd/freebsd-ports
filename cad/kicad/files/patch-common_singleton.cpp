commit 6e6db6de8f75041a394e11e89f2df2d6d842d27e
Author: Christoph Moench-Tegeder <cmt@burggraben.net>

    make thread priority setting optional
    
    thread priority setting is only available as part of the native
    extensions

diff --git common/singleton.cpp common/singleton.cpp
index df61f3caef..7ba4d9e3bd 100644
--- common/singleton.cpp
+++ common/singleton.cpp
@@ -59,6 +59,7 @@ void KICAD_SINGLETON::Init()
 {
     int num_threads = std::max( 0, ADVANCED_CFG::GetCfg().m_MaximumThreads );
 
+#ifdef BS_THREAD_POOL_NATIVE_EXTENSIONS
     m_ThreadPool = new BS::priority_thread_pool( num_threads,
                                                  []
                                                  {
@@ -66,6 +67,9 @@ void KICAD_SINGLETON::Init()
                                                      BS::this_thread::set_os_thread_priority(
                                                              BS::os_thread_priority::below_normal );
                                                  } );
+#else
+    m_ThreadPool = new BS::priority_thread_pool( num_threads );
+#endif
 
     m_GLContextManager = new GL_CONTEXT_MANAGER();
 }
