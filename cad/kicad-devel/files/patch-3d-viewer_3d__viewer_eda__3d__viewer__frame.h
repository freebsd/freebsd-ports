--- 3d-viewer/3d_viewer/eda_3d_viewer_frame.h.orig	2025-08-26 07:56:54 UTC
+++ 3d-viewer/3d_viewer/eda_3d_viewer_frame.h
@@ -44,7 +44,7 @@
 #define KICAD_DEFAULT_3D_DRAWFRAME_STYLE    (wxDEFAULT_FRAME_STYLE | wxWANTS_CHARS)
 
 // Forward declarations
-#ifdef __linux__
+#if defined (__linux__) || defined (__FreeBSD__)
 class SPNAV_VIEWER_PLUGIN;
 #else
 class NL_3D_VIEWER_PLUGIN;
@@ -280,7 +280,7 @@ class EDA_3D_VIEWER_FRAME : public KIWAY_PLAYER (priva
 
     bool                           m_disable_ray_tracing;
 
-#ifdef __linux__
+#if defined (__linux__) || defined (__FreeBSD__)
     std::unique_ptr<SPNAV_VIEWER_PLUGIN> m_spaceMouse;
 #else
     std::unique_ptr<NL_3D_VIEWER_PLUGIN> m_spaceMouse;
