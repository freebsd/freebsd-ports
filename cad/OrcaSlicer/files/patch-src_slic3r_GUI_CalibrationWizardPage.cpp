--- src/slic3r/GUI/CalibrationWizardPage.cpp.orig	2025-03-01 00:00:00 UTC
+++ src/slic3r/GUI/CalibrationWizardPage.cpp
@@ -424,7 +424,7 @@
         wxPostEvent(m_parent, event);
         });

-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
     wxGetApp().CallAfter([this, title_text]() {
         title_text->SetMinSize(title_text->GetSize() + wxSize{ FromDIP(150), title_text->GetCharHeight() / 2 });
         Layout();
