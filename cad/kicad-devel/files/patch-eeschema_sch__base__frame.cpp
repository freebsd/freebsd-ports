--- eeschema/sch_base_frame.cpp.orig	2025-09-14 17:37:19 UTC
+++ eeschema/sch_base_frame.cpp
@@ -61,7 +61,7 @@
 #include <wx/log.h>
 #include <wx/msgdlg.h>
 
-#ifndef __linux__
+#if not defined (__linux__) && not defined (__FreeBSD__)
 #include <navlib/nl_schematic_plugin.h>
 #include <wx/fdrepdlg.h>
 #else
@@ -370,7 +370,7 @@ void SCH_BASE_FRAME::ActivateGalCanvas()
     {
         if( !m_spaceMouse )
         {
-#ifndef __linux__
+#if not defined (__linux__) && not defined (__FreeBSD__)
             m_spaceMouse = std::make_unique<NL_SCHEMATIC_PLUGIN>();
 #else
             m_spaceMouse = std::make_unique<SPNAV_2D_PLUGIN>( GetCanvas() );
