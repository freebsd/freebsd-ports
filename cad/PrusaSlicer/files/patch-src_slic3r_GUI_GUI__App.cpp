--- src/slic3r/GUI/GUI_App.cpp.orig	2024-09-18 13:39:04 UTC
+++ src/slic3r/GUI/GUI_App.cpp
@@ -412,7 +412,7 @@ class SplashScreen : public wxSplashScreen (private)
 };
 
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
 bool static check_old_linux_datadir(const wxString& app_name) {
     // If we are on Linux and the datadir does not exist yet, look into the old
     // location where the datadir was before version 2.3. If we find it there,
@@ -1256,6 +1256,9 @@ bool GUI_App::on_init_inner()
     // Set initialization of image handlers before any UI actions - See GH issue #7469
     wxInitAllImageHandlers();
 
+	// Silence warnings generated with wxWidgets 3.2
+	wxSizerFlags::DisableConsistencyChecks();
+
     // Set our own gui log as an active target
     m_log_gui = new LogGui();
     wxLog::SetActiveTarget(m_log_gui);
@@ -1286,7 +1289,7 @@ bool GUI_App::on_init_inner()
     const wxString resources_dir = from_u8(Slic3r::resources_dir());
     wxCHECK_MSG(wxDirExists(resources_dir), false, wxString::Format("Resources path does not exist or is not a directory: %s", resources_dir));
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
     if (! check_old_linux_datadir(GetAppName())) {
         std::cerr << "Quitting, user chose to move their data to new location." << std::endl;
         return false;
@@ -1391,7 +1394,7 @@ bool GUI_App::on_init_inner()
         if (!default_splashscreen_pos)
             // revert "restore_win_position" value if application wasn't crashed
             get_app_config()->set("restore_win_position", "1");
-#ifndef __linux__
+#if !defined(__linux__) && !defined(__FreeBSD__)
         wxYield();
 #endif
         scrn->SetText(_L("Loading configuration")+ dots);
@@ -1557,7 +1560,7 @@ bool GUI_App::on_init_inner()
         // and wxEVT_SET_FOCUS before GUI_App::post_init is called) wasn't called before GUI_App::post_init and OpenGL wasn't initialized.
         // Since issue #9774 Where same problem occured on MacOS Ventura, we decided to have this check on MacOS as well.
 
-#if defined(__linux__) || defined(__APPLE__)
+#if defined(__linux__) || defined(__FreeBSD__) || defined(__APPLE__)
         if (!m_post_initialized && m_opengl_initialized) {
 #else
         if (!m_post_initialized) {
@@ -2247,7 +2250,7 @@ bool GUI_App::switch_language()
     }
 }
 
-#ifdef __linux__
+#if defined(__linux__) || (__FreeBSD__)
 static const wxLanguageInfo* linux_get_existing_locale_language(const wxLanguageInfo* language,
                                                                 const wxLanguageInfo* system_language)
 {
@@ -2449,7 +2452,7 @@ bool GUI_App::load_language(wxString language, bool in
 				m_language_info_best = wxLocale::FindLanguageInfo(best_language);
 	        	BOOST_LOG_TRIVIAL(trace) << boost::format("Best translation language detected (may be different from user locales): %1%") % m_language_info_best->CanonicalName.ToUTF8().data();
 			}
-            #ifdef __linux__
+            #if defined(__linux__) || defined(__FreeBSD__)
             wxString lc_all;
             if (wxGetEnv("LC_ALL", &lc_all) && ! lc_all.IsEmpty()) {
                 // Best language returned by wxWidgets on Linux apparently does not respect LC_ALL.
@@ -2458,6 +2461,7 @@ bool GUI_App::load_language(wxString language, bool in
             }
             #endif
 		}
+		m_language_info_best = nullptr;
     }
 
 	const wxLanguageInfo *language_info = language.empty() ? nullptr : wxLocale::FindLanguageInfo(language);
@@ -2502,7 +2506,7 @@ bool GUI_App::load_language(wxString language, bool in
     } else if (m_language_info_system != nullptr && language_info->CanonicalName.BeforeFirst('_') == m_language_info_system->CanonicalName.BeforeFirst('_'))
         language_info = m_language_info_system;
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
     // If we can't find this locale , try to use different one for the language
     // instead of just reporting that it is impossible to switch.
     if (! wxLocale::IsAvailable(language_info->Language)) {
@@ -2623,7 +2627,7 @@ wxMenu* GUI_App::get_config_menu(MainFrame* main_frame
         local_menu->Append(config_id_base + ConfigMenuTakeSnapshot, _L("Take Configuration &Snapshot"), _L("Capture a configuration snapshot"));
         local_menu->Append(config_id_base + ConfigMenuUpdateConf, _L("Check for Configuration Updates"), _L("Check for configuration updates"));
         local_menu->Append(config_id_base + ConfigMenuUpdateApp, _L("Check for Application Updates"), _L("Check for new version of application"));
-#if defined(__linux__) && defined(SLIC3R_DESKTOP_INTEGRATION) 
+#if (defined(__linux__) || defined(__FreeBSD__)) && defined(SLIC3R_DESKTOP_INTEGRATION) 
         //if (DesktopIntegrationDialog::integration_possible())
         local_menu->Append(config_id_base + ConfigMenuDesktopIntegration, _L("Desktop Integration"), _L("Desktop Integration"));    
 #endif //(__linux__) && defined(SLIC3R_DESKTOP_INTEGRATION)        
@@ -2657,7 +2661,7 @@ wxMenu* GUI_App::get_config_menu(MainFrame* main_frame
         case ConfigMenuUpdateApp:
             app_version_check(true);
             break;
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
         case ConfigMenuDesktopIntegration:
             show_desktop_integration_dialog();
             break;
@@ -3336,7 +3340,7 @@ void GUI_App::show_desktop_integration_dialog()
 
 void GUI_App::show_desktop_integration_dialog()
 {
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
     //wxCHECK_MSG(mainframe != nullptr, false, "Internal error: Main frame not created / null");
     DesktopIntegrationDialog dialog(mainframe);
     dialog.ShowModal();
@@ -3356,7 +3360,7 @@ void GUI_App::show_downloader_registration_dialog()
     if (msg.ShowModal() == wxID_YES) {
         auto downloader_worker = new DownloaderUtils::Worker(nullptr);
         downloader_worker->perform_download_register(app_config->get("url_downloader_dest"));
-#if defined(__linux__) && defined(SLIC3R_DESKTOP_INTEGRATION) 
+#if (defined(__linux__) || defined(__FreeBSD__)) && defined(SLIC3R_DESKTOP_INTEGRATION)
         if (DownloaderUtils::Worker::perform_registration_linux)
             DesktopIntegrationDialog::perform_downloader_desktop_integration();
 #endif //(__linux__) && defined(SLIC3R_DESKTOP_INTEGRATION)
@@ -3790,7 +3794,7 @@ void GUI_App::start_download(std::string url)
         return; 
     }
 
-    #if defined(__APPLE__) || (defined(__linux__) && !defined(SLIC3R_DESKTOP_INTEGRATION))
+    #if defined(__APPLE__) || ((defined(__linux__) || defined(__FreeBSD__)) && !defined(SLIC3R_DESKTOP_INTEGRATION))
     if (app_config && !app_config->get_bool("downloader_url_registered"))
     {
         notification_manager()->push_notification(NotificationType::URLNotRegistered);
