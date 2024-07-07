--- src/slic3r/GUI/Preferences.cpp.orig	2024-06-27 09:25:47 UTC
+++ src/slic3r/GUI/Preferences.cpp
@@ -29,7 +29,7 @@
 #ifdef WIN32
 #include <wx/msw/registry.h>
 #endif // WIN32
-#if defined(__linux__) && defined(SLIC3R_DESKTOP_INTEGRATION)
+#if (defined(__linux__) || defined(__FreeBSD__)) && defined(SLIC3R_DESKTOP_INTEGRATION)
 #include "DesktopIntegrationDialog.hpp"
 #endif //(__linux__) && defined(SLIC3R_DESKTOP_INTEGRATION)
 
@@ -267,7 +267,7 @@ void PreferencesDialog::build()
 	tabs = new Notebook(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxNB_TOP | wxTAB_TRAVERSAL | wxNB_NOPAGETHEME | wxNB_DEFAULT);
 #else
     tabs = new wxNotebook(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxNB_TOP | wxTAB_TRAVERSAL  |wxNB_NOPAGETHEME | wxNB_DEFAULT );
-#ifdef __linux__
+#if defined __linux__ || defined __FreeBSD__
 	tabs->Bind(wxEVT_NOTEBOOK_PAGE_CHANGED, [this](wxBookCtrlEvent& e) {
 		e.Skip();
 		CallAfter([this]() { tabs->GetCurrentPage()->Layout(); });
@@ -752,7 +752,7 @@ void PreferencesDialog::accept(wxEvent&)
 			downloader->allow(it->second == "1");
 		if (!downloader->on_finish())
 			return;
-#if defined(__linux__) && defined(SLIC3R_DESKTOP_INTEGRATION) 
+#if (defined(__linux__) || defined(__FreeBSD__)) && defined(SLIC3R_DESKTOP_INTEGRATION) 
 		if(DownloaderUtils::Worker::perform_registration_linux) 
 			DesktopIntegrationDialog::perform_downloader_desktop_integration();
 #endif //(__linux__) && defined(SLIC3R_DESKTOP_INTEGRATION)
@@ -1111,7 +1111,7 @@ void PreferencesDialog::create_settings_font_widget()
 		font_example->SetFont(font);
 		m_values[opt_key] = format("%1%", val);
 		stb_sizer->Layout();
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
 		CallAfter([this]() { refresh_og(m_optgroup_other); });
 #else
 		refresh_og(m_optgroup_other);
