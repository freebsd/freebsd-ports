--- src/slic3r/GUI/ExtraRenderers.cpp.orig	2023-07-25 09:27:23 UTC
+++ src/slic3r/GUI/ExtraRenderers.cpp
@@ -327,7 +327,7 @@ wxWindow* BitmapChoiceRenderer::CreateEditorCtrl(wxWin
     c_editor->SetSelection(atoi(data.GetText().c_str()));
 
     
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
     c_editor->Bind(wxEVT_COMBOBOX, [this](wxCommandEvent& evt) {
         // to avoid event propagation to other sidebar items
         evt.StopPropagation();
