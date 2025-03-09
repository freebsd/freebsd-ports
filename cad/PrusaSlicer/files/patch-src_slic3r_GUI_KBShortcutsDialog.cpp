--- src/slic3r/GUI/KBShortcutsDialog.cpp.orig	2024-12-20 11:54:34 UTC
+++ src/slic3r/GUI/KBShortcutsDialog.cpp
@@ -59,7 +59,7 @@ KBShortcutsDialog::KBShortcutsDialog()
     main_sizer->SetSizeHints(this);
     this->CenterOnParent();
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
     // workaround to correct pages layout
     book->Bind(wxEVT_NOTEBOOK_PAGE_CHANGED, [book](wxBookCtrlEvent& e) {
         book->GetPage(e.GetSelection())->Fit();
