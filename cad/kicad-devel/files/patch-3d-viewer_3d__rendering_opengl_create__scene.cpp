--- 3d-viewer/3d_rendering/opengl/create_scene.cpp.orig	2026-11-14 11:04:10 UTC
+++ 3d-viewer/3d_rendering/opengl/create_scene.cpp
@@ -1230,7 +1230,9 @@ void RENDER_3D_OPENGL::startBgWorker()
             [this]( std::stop_token aStopToken )
             {
                 // Avoid lag in main (UI) thread
+#ifdef BS_THREAD_POOL_NATIVE_EXTENSIONS
                 BS::this_thread::set_os_thread_priority( BS::os_thread_priority::below_normal );
+#endif
 
                 bgWorker( aStopToken );
 
@@ -1250,7 +1252,9 @@ void RENDER_3D_OPENGL::RebuildHitTestAsync()
     m_bgWorkerThread = std::jthread(
             [this]( std::stop_token aStop )
             {
+#ifdef BS_THREAD_POOL_NATIVE_EXTENSIONS
                 BS::this_thread::set_os_thread_priority( BS::os_thread_priority::below_normal );
+#endif
 
                 runHitTestRebuild( aStop );
 
