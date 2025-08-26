--- pagelayout_editor/pl_editor_frame.h.orig	2025-08-26 08:10:05 UTC
+++ pagelayout_editor/pl_editor_frame.h
@@ -39,7 +39,7 @@ class wxChoice;
 class DS_DATA_ITEM;
 class wxChoice;
 
-#ifndef __linux__
+#if not defined (__linux__) && not defined (__FreeBSD__)
 class NL_PL_EDITOR_PLUGIN;
 #else
 class SPNAV_2D_PLUGIN;
@@ -274,7 +274,7 @@ class PL_EDITOR_FRAME : public EDA_DRAW_FRAME (private
                                               // only on page 1, not on page 1
     VECTOR2I          m_grid_origin;
 
-#ifndef __linux__
+#if not defined (__linux__) && not defined (__FreeBSD__)
     std::unique_ptr<NL_PL_EDITOR_PLUGIN> m_spaceMouse;
 #else
     std::unique_ptr<SPNAV_2D_PLUGIN> m_spaceMouse;
