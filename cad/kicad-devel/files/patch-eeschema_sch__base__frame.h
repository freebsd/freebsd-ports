--- eeschema/sch_base_frame.h.orig	2025-08-26 07:58:54 UTC
+++ eeschema/sch_base_frame.h
@@ -56,7 +56,7 @@ class SYMBOL_EDITOR_SETTINGS;
 class EESCHEMA_SETTINGS;
 class SYMBOL_EDITOR_SETTINGS;
 
-#ifndef __linux__
+#if not defined (__linux__) && not defined (__FreeBSD__)
 class NL_SCHEMATIC_PLUGIN;
 #else
 class SPNAV_2D_PLUGIN;
@@ -333,7 +333,7 @@ class SCH_BASE_FRAME : public EDA_DRAW_FRAME, public S
     wxTimer                                 m_watcherDebounceTimer;
     bool                                    m_inSymChangeTimerEvent;
 
-#ifndef __linux__
+#if not defined (__linux__) && not defined (__FreeBSD__)
     std::unique_ptr<NL_SCHEMATIC_PLUGIN>    m_spaceMouse;
 #else
     std::unique_ptr<SPNAV_2D_PLUGIN>        m_spaceMouse;
