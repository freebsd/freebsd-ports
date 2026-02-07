--- gerbview/gerbview_frame.h.orig	2025-08-26 08:11:04 UTC
+++ gerbview/gerbview_frame.h
@@ -46,7 +46,7 @@ class wxStaticText;
 class SELECTION;
 class wxStaticText;
 
-#ifndef __linux__
+#if not defined (__linux__) && not defined (__FreeBSD__)
 class NL_GERBVIEW_PLUGIN;
 #else
 class SPNAV_2D_PLUGIN;
@@ -526,7 +526,7 @@ class GERBVIEW_FRAME : public EDA_DRAW_FRAME (private)
     wxStaticText*       m_dcodeText;        // a message on the auxiliary toolbar,
                                             // relative to the m_DCodeSelector
 
-#ifndef __linux__
+#if not defined (__linux__) && not defined (__FreeBSD__)
     std::unique_ptr<NL_GERBVIEW_PLUGIN> m_spaceMouse;
 #else
     std::unique_ptr<SPNAV_2D_PLUGIN> m_spaceMouse;
