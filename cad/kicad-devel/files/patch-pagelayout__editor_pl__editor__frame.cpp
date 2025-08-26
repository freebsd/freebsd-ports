--- pagelayout_editor/pl_editor_frame.cpp.orig	2025-08-26 08:01:02 UTC
+++ pagelayout_editor/pl_editor_frame.cpp
@@ -65,7 +65,7 @@
 #include <wx/msgdlg.h>
 #include <wx/log.h>
 
-#ifndef __linux__
+#if not defined (__linux__) && not defined (__FreeBSD__)
 #include <navlib/nl_pl_editor_plugin.h>
 #else
 #include <spacenav/spnav_2d_plugin.h>
@@ -240,7 +240,7 @@ PL_EDITOR_FRAME::PL_EDITOR_FRAME( KIWAY* aKiway, wxWin
     {
         if( !m_spaceMouse )
         {
-#ifndef __linux__
+#if not defined (__linux__) && not defined (__FreeBSD__)
             m_spaceMouse = std::make_unique<NL_PL_EDITOR_PLUGIN>();
 #else
             m_spaceMouse = std::make_unique<SPNAV_2D_PLUGIN>( GetCanvas() );
