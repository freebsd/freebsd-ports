--- src/slic3r/GUI/Plater.cpp.orig	2026-03-22 17:56:38 UTC
+++ src/slic3r/GUI/Plater.cpp
@@ -529,7 +529,9 @@
         //if (isBBL) {
             wxBoxSizer *hsizer = new wxBoxSizer(wxHORIZONTAL);
             hsizer->Add(image_printer, 0, wxLEFT  | wxALIGN_LEFT  | wxALIGN_CENTER_VERTICAL, FromDIP(10));
-            hsizer->Add(combo_printer, 1, wxEXPAND | wxALL | wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL, FromDIP(2));
+            // Drop wxALIGN_* here; wxEXPAND overrides alignment in a box sizer, and the
+            // combination trips wx's sizer-flags consistency check.
+            hsizer->Add(combo_printer, 1, wxEXPAND | wxALL, FromDIP(2));
             hsizer->AddSpacer(FromDIP(2));
             hsizer->Add(btn_edit_printer, 0, wxRIGHT | wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL, FromDIP(SidebarProps::IconSpacing()));
             //hsizer->Add(btn_connect_printer, 0, wxRIGHT | wxALIGN_RIGHT | wxALIGN_CENTER_VERTICAL, FromDIP(SidebarProps::IconSpacing()));
@@ -8886,9 +8888,6 @@
     if (!old_panel) {
         //BBS: only switch to the first panel when visible
         panel->Show();
-        //dynamic_cast<View3D *>(panel)->get_canvas3d()->render();
-        if (!panel->IsShownOnScreen())
-            return;
     }
 //#endif
     current_panel = panel;
