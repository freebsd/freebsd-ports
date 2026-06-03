--- src/slic3r/GUI/CalibrationWizardPage.cpp.orig	2026-03-22 17:56:38 UTC
+++ src/slic3r/GUI/CalibrationWizardPage.cpp
@@ -448,7 +448,7 @@ CaliPageCaption::CaliPageCaption(wxWindow* parent, Cal
         wxPostEvent(m_parent, event);
         });
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
     wxGetApp().CallAfter([this, title_text]() {
         title_text->SetMinSize(title_text->GetSize() + wxSize{ FromDIP(150), title_text->GetCharHeight() / 2 });
         Layout();
