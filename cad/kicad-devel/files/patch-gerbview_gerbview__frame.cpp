--- gerbview/gerbview_frame.cpp.orig	2025-08-26 08:02:01 UTC
+++ gerbview/gerbview_frame.cpp
@@ -59,7 +59,7 @@
 #include "widgets/dcode_selection_box.h"
 #include <dialog_draw_layers_settings.h>
 
-#ifndef __linux__
+#if not defined (__linux__) && not defined (__FreeBSD__)
 #include <navlib/nl_gerbview_plugin.h>
 #else
 #include <spacenav/spnav_2d_plugin.h>
@@ -1045,7 +1045,7 @@ void GERBVIEW_FRAME::ActivateGalCanvas()
     {
         if( !m_spaceMouse )
         {
-#ifndef __linux__
+#if not defined (__linux__) && not defined (__FreeBSD__)
             m_spaceMouse = std::make_unique<NL_GERBVIEW_PLUGIN>();
 #else
             m_spaceMouse = std::make_unique<SPNAV_2D_PLUGIN>( galCanvas );
