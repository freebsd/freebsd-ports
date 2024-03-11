--- src/slic3r/GUI/ConfigWizard.cpp.orig	2024-02-29 13:03:32 UTC
+++ src/slic3r/GUI/ConfigWizard.cpp
@@ -69,7 +69,7 @@
 #include "slic3r/GUI/I18N.hpp"
 #include "slic3r/Config/Version.hpp"
 
-#if defined(__linux__) && defined(__WXGTK3__)
+#if (defined(__linux__) || defined(__FreeBSD__)) && defined(__WXGTK3__)
 #define wxLinux_gtk3 true
 #else
 #define wxLinux_gtk3 false
@@ -596,7 +596,7 @@ void PageWelcome::set_run_reason(ConfigWizard::RunReas
     const bool data_empty = run_reason == ConfigWizard::RR_DATA_EMPTY;
     welcome_text->Show(data_empty);
     cbox_reset->Show(!data_empty);
-#if defined(__linux__) && defined(SLIC3R_DESKTOP_INTEGRATION)
+#if (defined(__linux__) || defined(__FreeBSD__)) && defined(SLIC3R_DESKTOP_INTEGRATION)
     if (!DesktopIntegrationDialog::is_integrated())
         cbox_integrate->Show(true);
     else
@@ -1518,7 +1518,7 @@ PageDownloader::PageDownloader(ConfigWizard* parent)
         ));
     }
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
     append_text(wxString::Format(_L(
         "On Linux systems the process of registration also creates desktop integration files for this version of application."
     )));
@@ -1579,7 +1579,7 @@ bool DownloaderUtils::Worker::perform_register(const s
     }
     //key_full = "\"C:\\Program Files\\Prusa3D\\PrusaSlicer\\prusa-slicer-console.exe\" \"%1\"";
     key_full = key_string;
-#elif __APPLE__
+#elif defined(__APPLE__) || defined(__FreeBSD__)
     // Apple registers for custom url in info.plist thus it has to be already registered since build.
     // The url will always trigger opening of prusaslicer and we have to check that user has allowed it. (GUI_App::MacOpenURL is the triggered method)
 #else 
@@ -1598,7 +1598,7 @@ void DownloaderUtils::Worker::deregister()
         return;
     }
     key_full = key_string;
-#elif __APPLE__
+#elif defined(__APPLE__) || defined(__FreeBSD__)
     // TODO
 #else 
     BOOST_LOG_TRIVIAL(debug) << "DesktopIntegrationDialog::undo_downloader_registration";
@@ -3063,7 +3063,7 @@ bool ConfigWizard::priv::apply_config(AppConfig *app_c
         if ((check_unsaved_preset_changes = install_bundles.size() > 0))
             header = _L_PLURAL("A new vendor was installed and one of its printers will be activated", "New vendors were installed and one of theirs printers will be activated", install_bundles.size());
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
     // Desktop integration on Linux
     BOOST_LOG_TRIVIAL(debug) << "ConfigWizard::priv::apply_config integrate_desktop" << page_welcome->integrate_desktop()  << " perform_registration_linux " << page_downloader->m_downloader->get_perform_registration_linux();
     if (page_welcome->integrate_desktop())
