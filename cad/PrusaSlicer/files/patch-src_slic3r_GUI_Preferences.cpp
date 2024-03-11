--- src/slic3r/GUI/Preferences.cpp.orig	2023-12-12 14:21:21 UTC
+++ src/slic3r/GUI/Preferences.cpp
@@ -28,7 +28,7 @@
 #ifdef WIN32
 #include <wx/msw/registry.h>
 #endif // WIN32
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
 #include "DesktopIntegrationDialog.hpp"
 #endif //__linux__
 
@@ -758,7 +758,7 @@ void PreferencesDialog::accept(wxEvent&)
 			downloader->allow(it->second == "1");
 		if (!downloader->on_finish())
 			return;
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
 		if( downloader->get_perform_registration_linux()) 
 			DesktopIntegrationDialog::perform_downloader_desktop_integration();
 #endif // __linux__
