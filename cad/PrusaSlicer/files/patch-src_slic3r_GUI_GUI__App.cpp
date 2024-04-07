--- src/slic3r/GUI/GUI_App.cpp.orig	2024-04-05 09:25:31 UTC
+++ src/slic3r/GUI/GUI_App.cpp
@@ -403,7 +403,7 @@ class SplashScreen : public wxSplashScreen (private)
 };
 
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
 bool static check_old_linux_datadir(const wxString& app_name) {
     // If we are on Linux and the datadir does not exist yet, look into the old
     // location where the datadir was before version 2.3. If we find it there,
@@ -937,7 +937,7 @@ void GUI_App::init_app_config()
 	// Mac : "~/Library/Application Support/Slic3r"
 
     if (data_dir().empty()) {
-        #ifndef __linux__
+        #if !defined(__linux__) && !defined(__FreeBSD__)
             set_data_dir(wxStandardPaths::Get().GetUserDataDir().ToUTF8().data());
         #else
             // Since version 2.3, config dir on Linux is in ${XDG_CONFIG_HOME}.
@@ -1107,7 +1107,8 @@ bool GUI_App::on_init_inner()
 
     // Set initialization of image handlers before any UI actions - See GH issue #7469
     wxInitAllImageHandlers();
-
+    // Silence warnings generated with wxWidgets 3.2
+    wxSizerFlags::DisableConsistencyChecks();
 #if defined(_WIN32) && ! defined(_WIN64)
     // Win32 32bit build.
     if (wxPlatformInfo::Get().GetArchName().substr(0, 2) == "64") {
@@ -1135,7 +1136,7 @@ bool GUI_App::on_init_inner()
     wxCHECK_MSG(wxDirExists(resources_dir), false,
         wxString::Format("Resources path does not exist or is not a directory: %s", resources_dir));
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
     if (! check_old_linux_datadir(GetAppName())) {
         std::cerr << "Quitting, user chose to move their data to new location." << std::endl;
         return false;
@@ -1240,7 +1241,7 @@ bool GUI_App::on_init_inner()
         if (!default_splashscreen_pos)
             // revert "restore_win_position" value if application wasn't crashed
             get_app_config()->set("restore_win_position", "1");
-#ifndef __linux__
+#if !defined(__linux__) && !defined(__FreeBSD__)
         wxYield();
 #endif
         scrn->SetText(_L("Loading configuration")+ dots);
@@ -1393,7 +1394,7 @@ bool GUI_App::on_init_inner()
         // and wxEVT_SET_FOCUS before GUI_App::post_init is called) wasn't called before GUI_App::post_init and OpenGL wasn't initialized.
         // Since issue #9774 Where same problem occured on MacOS Ventura, we decided to have this check on MacOS as well.
 
-#if defined(__linux__) || defined(__APPLE__)
+#if defined(__linux__) || defined(__FreeBSD__) || defined(__APPLE__)
         if (!m_post_initialized && m_opengl_initialized) {
 #else
         if (!m_post_initialized) {
@@ -2096,7 +2097,7 @@ bool GUI_App::switch_language()
     }
 }
 
-#ifdef __linux__
+#if defined(__linux__) || (__FreeBSD__)
 static const wxLanguageInfo* linux_get_existing_locale_language(const wxLanguageInfo* language,
                                                                 const wxLanguageInfo* system_language)
 {
@@ -2298,7 +2299,7 @@ bool GUI_App::load_language(wxString language, bool in
 				m_language_info_best = wxLocale::FindLanguageInfo(best_language);
 	        	BOOST_LOG_TRIVIAL(trace) << boost::format("Best translation language detected (may be different from user locales): %1%") % m_language_info_best->CanonicalName.ToUTF8().data();
 			}
-            #ifdef __linux__
+            #if defined(__linux__) || defined(__FreeBSD__)
             wxString lc_all;
             if (wxGetEnv("LC_ALL", &lc_all) && ! lc_all.IsEmpty()) {
                 // Best language returned by wxWidgets on Linux apparently does not respect LC_ALL.
@@ -2307,6 +2308,7 @@ bool GUI_App::load_language(wxString language, bool in
             }
             #endif
 		}
+		m_language_info_best = nullptr;
     }
 
 	const wxLanguageInfo *language_info = language.empty() ? nullptr : wxLocale::FindLanguageInfo(language);
@@ -2351,7 +2353,7 @@ bool GUI_App::load_language(wxString language, bool in
     } else if (m_language_info_system != nullptr && language_info->CanonicalName.BeforeFirst('_') == m_language_info_system->CanonicalName.BeforeFirst('_'))
         language_info = m_language_info_system;
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
     // If we can't find this locale , try to use different one for the language
     // instead of just reporting that it is impossible to switch.
     if (! wxLocale::IsAvailable(language_info->Language)) {
@@ -2471,7 +2473,7 @@ void GUI_App::add_config_menu(wxMenuBar *menu)
         local_menu->Append(config_id_base + ConfigMenuTakeSnapshot, _L("Take Configuration &Snapshot"), _L("Capture a configuration snapshot"));
         local_menu->Append(config_id_base + ConfigMenuUpdateConf, _L("Check for Configuration Updates"), _L("Check for configuration updates"));
         local_menu->Append(config_id_base + ConfigMenuUpdateApp, _L("Check for Application Updates"), _L("Check for new version of application"));
-#if defined(__linux__) && defined(SLIC3R_DESKTOP_INTEGRATION) 
+#if (defined(__linux__) || defined(__FreeBSD__)) && defined(SLIC3R_DESKTOP_INTEGRATION) 
         //if (DesktopIntegrationDialog::integration_possible())
         local_menu->Append(config_id_base + ConfigMenuDesktopIntegration, _L("Desktop Integration"), _L("Desktop Integration"));    
 #endif //(__linux__) && defined(SLIC3R_DESKTOP_INTEGRATION)        
@@ -2519,7 +2521,7 @@ void GUI_App::add_config_menu(wxMenuBar *menu)
         case ConfigMenuUpdateApp:
             app_version_check(true);
             break;
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
         case ConfigMenuDesktopIntegration:
             show_desktop_integration_dialog();
             break;
@@ -3149,7 +3151,7 @@ void GUI_App::show_desktop_integration_dialog()
 
 void GUI_App::show_desktop_integration_dialog()
 {
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
     //wxCHECK_MSG(mainframe != nullptr, false, "Internal error: Main frame not created / null");
     DesktopIntegrationDialog dialog(mainframe);
     dialog.ShowModal();
@@ -3169,7 +3171,7 @@ void GUI_App::show_downloader_registration_dialog()
     if (msg.ShowModal() == wxID_YES) {
         auto downloader_worker = new DownloaderUtils::Worker(nullptr);
         downloader_worker->perform_register(app_config->get("url_downloader_dest"));
-#if defined(__linux__) && defined(SLIC3R_DESKTOP_INTEGRATION) 
+#if (defined(__linux__) || defined(__FreeBSD__)) && defined(SLIC3R_DESKTOP_INTEGRATION) 
         if (downloader_worker->get_perform_registration_linux())
             DesktopIntegrationDialog::perform_downloader_desktop_integration();
 #endif //(__linux__) && defined(SLIC3R_DESKTOP_INTEGRATION)
