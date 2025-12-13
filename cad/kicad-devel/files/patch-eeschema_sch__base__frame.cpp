--- eeschema/sch_base_frame.cpp.orig	2025-12-12 23:35:14 UTC
+++ eeschema/sch_base_frame.cpp
@@ -65,7 +65,7 @@
 #include <wx/msgdlg.h>
 #include <trace_helpers.h>
 
-#ifndef __linux__
+#if not defined (__linux__) && not defined (__FreeBSD__)
 #include <navlib/nl_schematic_plugin.h>
 #include <wx/fdrepdlg.h>
 #else
@@ -338,7 +338,7 @@ void SCH_BASE_FRAME::ActivateGalCanvas()
     {
         if( !m_spaceMouse )
         {
-#ifndef __linux__
+#if not defined (__linux__) && not defined (__FreeBSD__)
             m_spaceMouse = std::make_unique<NL_SCHEMATIC_PLUGIN>();
 #else
             m_spaceMouse = std::make_unique<SPNAV_2D_PLUGIN>( GetCanvas() );
