--- src/slic3r/GUI/ExtraRenderers.cpp.orig	2026-03-22 17:56:38 UTC
+++ src/slic3r/GUI/ExtraRenderers.cpp
@@ -328,7 +328,7 @@ wxWindow* BitmapChoiceRenderer::CreateEditorCtrl(wxWin
     else
         c_editor->SetSelection(atoi(data.GetText().c_str()) - 1);
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
     c_editor->Bind(wxEVT_COMBOBOX, [this](wxCommandEvent& evt) {
         // to avoid event propagation to other sidebar items
         evt.StopPropagation();
