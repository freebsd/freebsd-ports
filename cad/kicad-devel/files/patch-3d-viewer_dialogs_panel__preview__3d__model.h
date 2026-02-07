--- 3d-viewer/dialogs/panel_preview_3d_model.h.orig	2025-08-26 08:13:34 UTC
+++ 3d-viewer/dialogs/panel_preview_3d_model.h
@@ -63,7 +63,7 @@ class FOOTPRINT;
 class BOARD;
 class BOARD_ADAPTER;
 class FOOTPRINT;
-#ifndef __linux__
+#if not defined (__linux__) && not defined (__FreeBSD__)
 class NL_FOOTPRINT_PROPERTIES_PLUGIN;
 #else
 class SPNAV_VIEWER_PLUGIN;
@@ -233,7 +233,7 @@ class PANEL_PREVIEW_3D_MODEL: public TOOLS_HOLDER, pub
     /// The 3d viewer Render initial settings (must be saved and restored)
     EDA_3D_VIEWER_SETTINGS::RENDER_SETTINGS          m_initialRender;
 
-#ifndef __linux__
+#if not defined (__linux__) && not defined (__FreeBSD__)
     std::unique_ptr<NL_FOOTPRINT_PROPERTIES_PLUGIN>  m_spaceMouse;
 #else
     std::unique_ptr<SPNAV_VIEWER_PLUGIN> m_spaceMouse;
