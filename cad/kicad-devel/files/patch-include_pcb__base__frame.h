--- include/pcb_base_frame.h.orig	2025-12-12 23:35:14 UTC
+++ include/pcb_base_frame.h
@@ -62,7 +62,7 @@ class PCB_LAYER_BOX_SELECTOR;
 class PROGRESS_REPORTER;
 class PCB_LAYER_BOX_SELECTOR;
 
-#ifndef __linux__
+#if not defined (__linux__) && not defined (__FreeBSD__)
 class NL_PCBNEW_PLUGIN;
 #else
 class SPNAV_2D_PLUGIN;
@@ -437,7 +437,7 @@ class PCB_BASE_FRAME : public EDA_DRAW_FRAME (private)
     PCB_ORIGIN_TRANSFORMS   m_originTransforms;
 
 private:
-#ifndef __linux__
+#if not defined (__linux__) && not defined (__FreeBSD__)
     std::unique_ptr<NL_PCBNEW_PLUGIN>    m_spaceMouse;
 #else
     std::unique_ptr<SPNAV_2D_PLUGIN>    m_spaceMouse;
