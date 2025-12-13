--- pcbnew/pcb_base_frame.cpp.orig	2025-12-12 23:35:14 UTC
+++ pcbnew/pcb_base_frame.cpp
@@ -68,7 +68,7 @@
 #include <tool/grid_menu.h>
 #include <ratsnest/ratsnest_view_item.h>
 
-#ifdef __linux__
+#if defined (__linux__) || defined (__FreeBSD__)
 #include <spacenav/spnav_2d_plugin.h>
 #else
 #include <navlib/nl_pcbnew_plugin.h>
@@ -1008,7 +1008,7 @@ void PCB_BASE_FRAME::ActivateGalCanvas()
     {
         if( !m_spaceMouse )
         {
-#ifndef __linux__
+#if not defined (__linux__) && not defined (__FreeBSD__)
             m_spaceMouse = std::make_unique<NL_PCBNEW_PLUGIN>( GetCanvas() );
 #else
             m_spaceMouse = std::make_unique<SPNAV_2D_PLUGIN>( GetCanvas() );
