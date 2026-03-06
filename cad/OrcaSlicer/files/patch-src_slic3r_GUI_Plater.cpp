--- src/slic3r/GUI/Plater.cpp.orig	2025-10-02 17:32:12 UTC
+++ src/slic3r/GUI/Plater.cpp
@@ -6369,9 +6369,6 @@ void Plater::priv::set_current_panel(wxPanel* panel, b
     if (!old_panel) {
         //BBS: only switch to the first panel when visible
         panel->Show();
-        //dynamic_cast<View3D *>(panel)->get_canvas3d()->render();
-        if (!panel->IsShownOnScreen())
-            return;
     }
 //#endif
     current_panel = panel;
