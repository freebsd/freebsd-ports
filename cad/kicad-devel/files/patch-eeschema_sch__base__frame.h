--- eeschema/sch_base_frame.h.orig	2025-12-12 23:35:14 UTC
+++ eeschema/sch_base_frame.h
@@ -59,7 +59,7 @@ struct SCH_SELECTION_FILTER_OPTIONS;
 class SYMBOL_EDITOR_SETTINGS;
 struct SCH_SELECTION_FILTER_OPTIONS;
 
-#ifndef __linux__
+#if not defined (__linux__) && not defined (__FreeBSD__)
 class NL_SCHEMATIC_PLUGIN;
 #else
 class SPNAV_2D_PLUGIN;
@@ -329,7 +329,7 @@ class SCH_BASE_FRAME : public EDA_DRAW_FRAME, public S
     wxTimer                                 m_watcherDebounceTimer;
     bool                                    m_inSymChangeTimerEvent;
 
-#ifndef __linux__
+#if not defined (__linux__) && not defined (__FreeBSD__)
     std::unique_ptr<NL_SCHEMATIC_PLUGIN>    m_spaceMouse;
 #else
     std::unique_ptr<SPNAV_2D_PLUGIN>        m_spaceMouse;
