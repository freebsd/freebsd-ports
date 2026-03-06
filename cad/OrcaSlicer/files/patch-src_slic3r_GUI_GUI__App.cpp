--- src/slic3r/GUI/GUI_App.cpp.orig	2025-10-02 17:32:12 UTC
+++ src/slic3r/GUI/GUI_App.cpp
@@ -468,7 +468,7 @@ class SplashScreen : public wxSplashScreen (private)
     m_constant_text;
 };
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
 bool static check_old_linux_datadir(const wxString& app_name) {
     // If we are on Linux and the datadir does not exist yet, look into the old
     // location where the datadir was before version 2.3. If we find it there,
@@ -886,6 +886,7 @@ void GUI_App::post_init()
         }
         else {
             BOOST_LOG_TRIVIAL(warning) << __FUNCTION__ << "Found glcontext not ready, postpone the init";
+            plater_->canvas3D()->enable_render(true);
         }
 //#endif
         if (is_editor())
@@ -1905,7 +1906,7 @@ bool GUI_App::init_opengl()
 
 bool GUI_App::init_opengl()
 {
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
     bool status = m_opengl_mgr.init_gl();
     m_opengl_initialized = true;
     return status;
@@ -1997,7 +1998,7 @@ void GUI_App::init_app_config()
         }
         else{
             boost::filesystem::path data_dir_path;
-            #ifndef __linux__
+            #if !defined(__linux__) && !defined(__FreeBSD__)
                 std::string data_dir = wxStandardPaths::Get().GetUserDataDir().ToUTF8().data();
                 //BBS create folder if not exists
                 data_dir_path = boost::filesystem::path(data_dir);
@@ -2097,7 +2098,7 @@ std::map<std::string, std::string> GUI_App::get_extra_
 #endif
 #elif defined(__APPLE__)
     extra_headers.insert(std::make_pair("X-BBL-OS-Type", "macos"));
-#elif defined(__LINUX__)
+#elif defined(__LINUX__) || defined(__FreeBSD__)
     extra_headers.insert(std::make_pair("X-BBL-OS-Type", "linux"));
 #endif
     int major = 0, minor = 0, micro = 0;
@@ -2298,7 +2299,7 @@ bool GUI_App::on_init_inner()
     wxCHECK_MSG(wxDirExists(resources_dir), false,
         wxString::Format(_L("Resources path does not exist or is not a directory: %s"), resources_dir));
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
     if (! check_old_linux_datadir(GetAppName())) {
         std::cerr << "Quitting, user chose to move their data to new location." << std::endl;
         return false;
@@ -2443,7 +2444,7 @@ bool GUI_App::on_init_inner()
 
         BOOST_LOG_TRIVIAL(info) << "begin to show the splash screen...";
         //BBS use BBL splashScreen
-        scrn = new SplashScreen(bmp, wxSPLASH_CENTRE_ON_SCREEN | wxSPLASH_TIMEOUT, 1500, splashscreen_pos);
+        scrn = new SplashScreen(bmp, wxSPLASH_CENTRE_ON_SCREEN, 0, splashscreen_pos);
         wxYield();
         scrn->SetText(_L("Loading configuration")+ dots);
     }
@@ -2676,6 +2677,11 @@ bool GUI_App::on_init_inner()
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
@@ -3014,7 +3020,7 @@ void GUI_App::init_label_colours()
     m_color_label_modified = is_dark_mode ? wxColour("#F1754E") : wxColour("#F1754E");
     m_color_label_sys      = is_dark_mode ? wxColour("#B2B3B5") : wxColour("#363636");
 
-#if defined(_WIN32) || defined(__linux__) || defined(__APPLE__)
+#if defined(_WIN32) || defined(__linux__) || defined(__APPLE__) || defined(__FreeBSD__)
     m_color_label_default           = is_dark_mode ? wxColour(250, 250, 250) : m_color_label_sys; // wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOWTEXT);
     m_color_highlight_label_default = is_dark_mode ? wxColour(230, 230, 230): wxSystemSettings::GetColour(/*wxSYS_COLOUR_HIGHLIGHTTEXT*/wxSYS_COLOUR_WINDOWTEXT);
     m_color_highlight_default       = is_dark_mode ? wxColour("#36363B") : wxColour("#F1F1F1"); // ORCA row highlighting
@@ -4322,7 +4328,7 @@ void GUI_App::check_new_version(bool show_tips, int by
 #ifdef __APPLE__
     platform = "macos";
 #endif
-#ifdef __LINUX__
+#if defined(__LINUX__) || defined(__FreeBSD__)
     platform = "linux";
 #endif
     std::string query_params = (boost::format("?name=slicer&version=%1%&guide_version=%2%")
@@ -4405,7 +4411,7 @@ std::string detect_updater_os()
     return "win";
 #elif defined(__APPLE__)
     return "macos";
-#elif defined(__linux__) || defined(__LINUX__)
+#elif defined(__linux__) || defined(__LINUX__) || defined(__FreeBSD__)
     return "linux";
 #else
     return "unknown";
@@ -5337,7 +5343,7 @@ bool GUI_App::switch_language()
     }
 }
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
 static const wxLanguageInfo* linux_get_existing_locale_language(const wxLanguageInfo* language,
                                                                 const wxLanguageInfo* system_language)
 {
@@ -5542,7 +5548,7 @@ bool GUI_App::load_language(wxString language, bool in
                                                         m_language_info_best->CanonicalName.ToUTF8().data();
                         app_config->set("language", m_language_info_best->CanonicalName.ToUTF8().data());
                     }
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
                     wxString lc_all;
                     if (wxGetEnv("LC_ALL", &lc_all) && !lc_all.IsEmpty()) {
                         // Best language returned by wxWidgets on Linux apparently does not respect LC_ALL.
@@ -5597,7 +5603,7 @@ bool GUI_App::load_language(wxString language, bool in
 		BOOST_LOG_TRIVIAL(info) << "Using Czech dictionaries for Slovak language";
     }
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
     // If we can't find this locale , try to use different one for the language
     // instead of just reporting that it is impossible to switch.
     if (! wxLocale::IsAvailable(language_info->Language) && m_language_info_system) {
@@ -6725,7 +6731,7 @@ void GUI_App::show_desktop_integration_dialog()
 
 void GUI_App::show_desktop_integration_dialog()
 {
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
     //wxCHECK_MSG(mainframe != nullptr, false, "Internal error: Main frame not created / null");
     DesktopIntegrationDialog dialog(mainframe);
     dialog.ShowModal();
@@ -7100,7 +7106,7 @@ void GUI_App::associate_url(std::wstring url_prefix)
         key_full.Create(false);
     }
     key_full = key_string;
-#elif defined(__linux__) && defined(SLIC3R_DESKTOP_INTEGRATION)
+#elif (defined(__linux__) || defined(__FreeBSD__)) && defined(SLIC3R_DESKTOP_INTEGRATION)
     DesktopIntegrationDialog::perform_downloader_desktop_integration(into_u8(url_prefix));
 #endif // WIN32
 }
