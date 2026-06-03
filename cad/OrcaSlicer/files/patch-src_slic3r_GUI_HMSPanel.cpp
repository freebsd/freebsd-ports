--- src/slic3r/GUI/HMSPanel.cpp.orig	2026-03-22 17:56:38 UTC
+++ src/slic3r/GUI/HMSPanel.cpp
@@ -70,7 +70,7 @@ HMSNotifyItem::HMSNotifyItem(const std::string& dev_id
     this->SetSizer(main_sizer);
     this->Layout();
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
     m_panel_hms->Bind(wxEVT_ENTER_WINDOW, [this](wxMouseEvent& e) {
         e.Skip();
         if (!m_url.empty()) {
