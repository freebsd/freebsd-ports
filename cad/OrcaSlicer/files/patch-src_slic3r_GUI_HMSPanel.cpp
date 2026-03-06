--- src/slic3r/GUI/HMSPanel.cpp.orig	2025-03-01 00:00:00 UTC
+++ src/slic3r/GUI/HMSPanel.cpp
@@ -69,7 +69,7 @@
     this->SetSizer(main_sizer);
     this->Layout();

-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
     m_panel_hms->Bind(wxEVT_ENTER_WINDOW, [this](wxMouseEvent& e) {
         e.Skip();
         if (!m_url.empty()) {
