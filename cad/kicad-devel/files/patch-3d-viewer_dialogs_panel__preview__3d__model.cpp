--- 3d-viewer/dialogs/panel_preview_3d_model.cpp.orig	2025-08-26 08:03:58 UTC
+++ 3d-viewer/dialogs/panel_preview_3d_model.cpp
@@ -47,7 +47,7 @@
 #include <eda_3d_viewer_settings.h>
 #include <board_design_settings.h>
 
-#ifndef __linux__
+#if not defined (__linux__) && not defined (__FreeBSD__)
 #include <3d_navlib/nl_footprint_properties_plugin.h>
 #else
 #include <3d_spacenav/spnav_viewer_plugin.h>
@@ -136,7 +136,7 @@ PANEL_PREVIEW_3D_MODEL::PANEL_PREVIEW_3D_MODEL( wxWind
 
     try
     {
-#ifndef __linux__
+#if not defined (__linux__) && not defined (__FreeBSD__)
         m_spaceMouse = std::make_unique<NL_FOOTPRINT_PROPERTIES_PLUGIN>( m_previewPane );
 #else
         m_spaceMouse = std::make_unique<SPNAV_VIEWER_PLUGIN>( m_previewPane );
