--- src/slic3r/GUI/KBShortcutsDialog.cpp.orig	2023-07-25 11:17:47 UTC
+++ src/slic3r/GUI/KBShortcutsDialog.cpp
@@ -54,7 +54,7 @@ KBShortcutsDialog::KBShortcutsDialog()
     main_sizer->SetSizeHints(this);
     this->CenterOnParent();
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
     // workaround to correct pages layout
     book->Bind(wxEVT_NOTEBOOK_PAGE_CHANGED, [book](wxBookCtrlEvent& e) {
         book->GetPage(e.GetSelection())->Fit();
