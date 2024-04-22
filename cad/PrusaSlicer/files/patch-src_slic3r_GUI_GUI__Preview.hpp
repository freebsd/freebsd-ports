--- src/slic3r/GUI/GUI_Preview.hpp.orig	2023-12-12 14:21:21 UTC
+++ src/slic3r/GUI/GUI_Preview.hpp
@@ -89,7 +89,7 @@ class Preview : public wxPanel
     BackgroundSlicingProcess* m_process;
     GCodeProcessorResult* m_gcode_result;
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
     // We are getting mysterious crashes on Linux in gtk due to OpenGL context activation GH #1874 #1955.
     // So we are applying a workaround here.
     bool m_volumes_cleanup_required { false };
