--- src/slic3r/GUI/Preferences.cpp.orig	2024-04-05 09:25:31 UTC
+++ src/slic3r/GUI/Preferences.cpp
@@ -28,7 +28,7 @@
 #ifdef WIN32
 #include <wx/msw/registry.h>
 #endif // WIN32
-#if defined(__linux__) && defined(SLIC3R_DESKTOP_INTEGRATION)
+#if (defined(__linux__) || defined(__FreeBSD__)) && defined(SLIC3R_DESKTOP_INTEGRATION)
 #include "DesktopIntegrationDialog.hpp"
 #endif //(__linux__) && defined(SLIC3R_DESKTOP_INTEGRATION)
 
@@ -758,7 +758,7 @@ void PreferencesDialog::accept(wxEvent&)
 			downloader->allow(it->second == "1");
 		if (!downloader->on_finish())
 			return;
-#if defined(__linux__) && defined(SLIC3R_DESKTOP_INTEGRATION) 
+#if (defined(__linux__) || defined(__FreeBSD__)) && defined(SLIC3R_DESKTOP_INTEGRATION) 
 		if( downloader->get_perform_registration_linux()) 
 			DesktopIntegrationDialog::perform_downloader_desktop_integration();
 #endif //(__linux__) && defined(SLIC3R_DESKTOP_INTEGRATION)
