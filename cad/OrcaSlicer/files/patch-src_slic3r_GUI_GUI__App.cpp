--- src/slic3r/GUI/GUI_App.cpp.orig	2026-03-22 17:56:38 UTC
+++ src/slic3r/GUI/GUI_App.cpp
@@ -38,6 +38,7 @@
 #include <wx/stdpaths.h>
 #include <wx/imagpng.h>
 #include <wx/display.h>
+#include <wx/sizer.h> // for wxSizerFlags::DisableConsistencyChecks()
 #include <wx/menu.h>
 #include <wx/menuitem.h>
 #include <wx/filedlg.h>
@@ -473,7 +474,7 @@ class SplashScreen : public wxSplashScreen (private)
     m_constant_text;
 };
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
 static void migrate_flatpak_legacy_datadir(const boost::filesystem::path &data_dir_path)
 {
     if(!boost::filesystem::exists("/.flatpak-info"))
@@ -927,6 +928,7 @@ void GUI_App::post_init()
         }
         else {
             BOOST_LOG_TRIVIAL(warning) << __FUNCTION__ << "Found glcontext not ready, postpone the init";
+            plater_->canvas3D()->enable_render(true);
         }
 //#endif
         if (is_editor())
@@ -2319,7 +2321,7 @@ bool GUI_App::init_opengl()
 
 bool GUI_App::init_opengl()
 {
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
     bool status = m_opengl_mgr.init_gl();
     m_opengl_initialized = true;
     return status;
@@ -2596,6 +2598,13 @@ bool GUI_App::OnInit()
 
 bool GUI_App::OnInit()
 {
+    // OrcaSlicer's UI passes wxSizer alignment flags that don't match the
+    // sizer orientation in many places. wxWidgets only ignores them, but
+    // our assert-enabled x11-toolkits/wxgtk* builds pop up a "DO NOT PANIC"
+    // dialog for each one. Disable the developer-only consistency checks so
+    // end users aren't spammed while the behavior is unchanged.
+    wxSizerFlags::DisableConsistencyChecks();
+
     try {
         return on_init_inner();
     } catch (const std::exception& e) {
@@ -2761,7 +2770,7 @@ bool GUI_App::on_init_inner()
     wxCHECK_MSG(wxDirExists(resources_dir), false,
         wxString::Format(_L("Resources path does not exist or is not a directory: %s"), resources_dir));
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
     if (! check_old_linux_datadir(GetAppName())) {
         std::cerr << "Quitting, user chose to move their data to new location." << std::endl;
         return false;
@@ -2907,7 +2916,7 @@ bool GUI_App::on_init_inner()
 
         BOOST_LOG_TRIVIAL(info) << "begin to show the splash screen...";
         //BBS use BBL splashScreen
-        scrn = new SplashScreen(bmp, wxSPLASH_CENTRE_ON_SCREEN | wxSPLASH_TIMEOUT, 1500, splashscreen_pos);
+        scrn = new SplashScreen(bmp, wxSPLASH_CENTRE_ON_SCREEN, 0, splashscreen_pos);
         wxYield();
         scrn->SetText(_L("Loading configuration")+ dots);
     }
@@ -3143,6 +3152,11 @@ bool GUI_App::on_init_inner()
     mainframe->Show(true);
     BOOST_LOG_TRIVIAL(info) << "main frame firstly shown";
 
+    if (scrn) {
+        scrn->Close();
+        scrn = nullptr;
+    }
+
 //#if BBL_HAS_FIRST_PAGE
     //BBS: set tp3DEditor firstly
     /*plater_->canvas3D()->enable_render(false);
@@ -5000,7 +5014,7 @@ void GUI_App::check_new_version(bool show_tips, int by
 #ifdef __APPLE__
     platform = "macos";
 #endif
-#ifdef __LINUX__
+#if defined(__linux__) || defined(__FreeBSD__)
     platform = "linux";
 #endif
     std::string query_params = (boost::format("?name=slicer&version=%1%&guide_version=%2%")
@@ -5083,7 +5097,7 @@ std::string detect_updater_os()
     return "win";
 #elif defined(__APPLE__)
     return "macos";
-#elif defined(__linux__) || defined(__LINUX__)
+#elif defined(__linux__) || defined(__LINUX__) || defined(__FreeBSD__)
     return "linux";
 #else
     return "unknown";
@@ -5332,6 +5346,8 @@ void GUI_App::check_new_version_sf(bool show_tips, int
 
 void GUI_App::check_new_version_sf(bool show_tips, int by_user)
 {
+    if (!by_user) return; // skip automatic update checks; allow manual ones
+
     AppConfig* app_config = wxGetApp().app_config;
     bool       check_stable_only = app_config->get_bool("check_stable_update_only");
     auto version_check_url = app_config->version_check_url();
@@ -6151,7 +6167,7 @@ bool GUI_App::switch_language()
     }
 }
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
 static const wxLanguageInfo* linux_get_existing_locale_language(const wxLanguageInfo* language,
                                                                 const wxLanguageInfo* system_language)
 {
@@ -6359,7 +6375,7 @@ bool GUI_App::load_language(wxString language, bool in
                                                         m_language_info_best->CanonicalName.ToUTF8().data();
                         app_config->set("language", m_language_info_best->CanonicalName.ToUTF8().data());
                     }
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
                     wxString lc_all;
                     if (wxGetEnv("LC_ALL", &lc_all) && !lc_all.IsEmpty()) {
                         // Best language returned by wxWidgets on Linux apparently does not respect LC_ALL.
@@ -6417,7 +6433,7 @@ bool GUI_App::load_language(wxString language, bool in
 		BOOST_LOG_TRIVIAL(info) << "Using Czech dictionaries for Slovak language";
     }
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
     // If we can't find this locale , try to use different one for the language
     // instead of just reporting that it is impossible to switch.
     if (!wxLocale::IsAvailable(locale_language_info->Language) && m_language_info_system) {
@@ -7599,7 +7615,7 @@ void GUI_App::show_desktop_integration_dialog()
 
 void GUI_App::show_desktop_integration_dialog()
 {
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
     //wxCHECK_MSG(mainframe != nullptr, false, "Internal error: Main frame not created / null");
     DesktopIntegrationDialog dialog(mainframe);
     dialog.ShowModal();
@@ -7985,7 +8001,7 @@ void GUI_App::associate_url(std::wstring url_prefix)
         key_full.Create(false);
     }
     key_full = key_string;
-#elif defined(__linux__) && defined(SLIC3R_DESKTOP_INTEGRATION)
+#elif (defined(__linux__) || defined(__FreeBSD__)) && defined(SLIC3R_DESKTOP_INTEGRATION)
     DesktopIntegrationDialog::perform_downloader_desktop_integration(into_u8(url_prefix));
 #endif // WIN32
 }
