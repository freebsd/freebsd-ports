--- 3d-viewer/3d_rendering/opengl/create_scene.cpp.orig	2026-10-01 19:47:08 UTC
+++ 3d-viewer/3d_rendering/opengl/create_scene.cpp
@@ -1171,7 +1171,9 @@ void RENDER_3D_OPENGL::startBgWorker()
             [this]( std::stop_token aStopToken )
             {
                 // Avoid lag in main (UI) thread
+#ifdef BS_THREAD_POOL_NATIVE_EXTENSIONS
                 BS::this_thread::set_os_thread_priority( BS::os_thread_priority::below_normal );
+#endif
 
                 bgWorker( aStopToken );
 
@@ -1191,7 +1193,9 @@ void RENDER_3D_OPENGL::RebuildHitTestAsync()
     m_bgWorkerThread = std::jthread(
             [this]( std::stop_token aStop )
             {
+#ifdef BS_THREAD_POOL_NATIVE_EXTENSIONS
                 BS::this_thread::set_os_thread_priority( BS::os_thread_priority::below_normal );
+#endif
 
                 runHitTestRebuild( aStop );
 
