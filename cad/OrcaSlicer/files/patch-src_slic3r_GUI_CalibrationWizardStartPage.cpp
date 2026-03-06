--- src/slic3r/GUI/CalibrationWizardStartPage.cpp.orig	2025-10-02 17:32:12 UTC
+++ src/slic3r/GUI/CalibrationWizardStartPage.cpp
@@ -128,7 +128,7 @@ void CalibrationPAStartPage::create_page(wxWindow* par
 
     m_top_sizer->Add(m_action_panel, 0, wxEXPAND, 0);
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
     wxGetApp().CallAfter([this]() {
         m_when_content->SetMinSize(m_when_content->GetSize() + wxSize{ 0, wxWindow::GetCharHeight() });
         m_about_content->SetMinSize(m_about_content->GetSize() + wxSize{ 0, wxWindow::GetCharHeight() });
@@ -270,7 +270,7 @@ void CalibrationFlowRateStartPage::create_page(wxWindo
 
     m_top_sizer->Add(m_action_panel, 0, wxEXPAND, 0);
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
     wxGetApp().CallAfter([this, auto_cali_content, extra_text]() {
         m_when_content->SetMinSize(m_when_content->GetSize() + wxSize{ 0, wxWindow::GetCharHeight() });
         auto_cali_content->SetMinSize(auto_cali_content->GetSize() + wxSize{ 0, wxWindow::GetCharHeight() });
