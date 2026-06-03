--- src/slic3r/GUI/Plater.cpp.orig	2026-03-22 17:56:38 UTC
+++ src/slic3r/GUI/Plater.cpp
@@ -8886,9 +8886,6 @@ void Plater::priv::set_current_panel(wxPanel* panel, b
     if (!old_panel) {
         //BBS: only switch to the first panel when visible
         panel->Show();
-        //dynamic_cast<View3D *>(panel)->get_canvas3d()->render();
-        if (!panel->IsShownOnScreen())
-            return;
     }
 //#endif
     current_panel = panel;
