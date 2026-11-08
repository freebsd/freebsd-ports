--- ui/zenoedit/launch/optixmain.cpp.orig	2024-09-30 13:46:54 UTC
+++ ui/zenoedit/launch/optixmain.cpp
@@ -44,7 +44,7 @@ int optix_main(const QCoreApplication& a
 
     zeno::set_log_stream(std::clog);
 
-    ZenoMainWindow tempWindow(nullptr, 0, PANEL_OPTIX_VIEW);
+    ZenoMainWindow tempWindow(nullptr, Qt::WindowFlags(), PANEL_OPTIX_VIEW);
     tempWindow.showMaximized();
     tempWindow.optixClientRun(port, cachedir, cachenum, sFrame, eFrame, finishedFrames, sessionId);
     return app.exec();
