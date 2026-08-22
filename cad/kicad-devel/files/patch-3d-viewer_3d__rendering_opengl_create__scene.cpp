--- 3d-viewer/3d_rendering/opengl/create_scene.cpp.orig	2026-08-22 14:48:47 UTC
+++ 3d-viewer/3d_rendering/opengl/create_scene.cpp
@@ -1155,7 +1155,9 @@ void RENDER_3D_OPENGL::startBgWorker()
             [this]( std::stop_token aStopToken )
             {
                 // Avoid lag in main (UI) thread
+#ifdef BS_THREAD_POOL_NATIVE_EXTENSIONS
                 BS::this_thread::set_os_thread_priority( BS::os_thread_priority::below_normal );
+#endif
 
                 bgWorker( aStopToken );
             } );
