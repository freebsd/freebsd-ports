--- 3d-viewer/3d_viewer/eda_3d_viewer_frame.cpp.orig	2025-08-25 16:19:00 UTC
+++ 3d-viewer/3d_viewer/eda_3d_viewer_frame.cpp
@@ -61,7 +61,7 @@
 #include <project_pcb.h>
 #include <toolbars_3d.h>
 
-#ifdef __linux__
+#if defined (__linux__) || defined (__FreeBSD__)
 #include <spacenav/libspnav_driver.h>
 #include <3d_spacenav/spnav_viewer_plugin.h>
 #else
@@ -197,7 +197,7 @@ EDA_3D_VIEWER_FRAME::EDA_3D_VIEWER_FRAME( KIWAY* aKiwa
 
     try
     {
-#ifdef __linux__
+#if defined (__linux__) || defined (__FreeBSD__)
         m_spaceMouse = std::make_unique<SPNAV_VIEWER_PLUGIN>( m_canvas );
 #else
         m_spaceMouse = std::make_unique<NL_3D_VIEWER_PLUGIN>( m_canvas );
