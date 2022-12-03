--- src/slic3r/GUI/GUI_App.cpp.orig	2022-09-06 07:09:19 UTC
+++ src/slic3r/GUI/GUI_App.cpp
@@ -2072,21 +2072,24 @@ bool GUI_App::load_language(wxString language, bool in
 	        	BOOST_LOG_TRIVIAL(trace) << boost::format("System language detected (user locales and such): %1%") % m_language_info_system->CanonicalName.ToUTF8().data();
 	        }
 		}
-        {
+        if (0) {
 	    	// Allocating a temporary locale will switch the default wxTranslations to its internal wxTranslations instance.
 	    	wxLocale temp_locale;
 	    	// Set the current translation's language to default, otherwise GetBestTranslation() may not work (see the wxWidgets source code).
-	    	wxTranslations::Get()->SetLanguage(wxLANGUAGE_DEFAULT);
-	    	// Let the wxFileTranslationsLoader enumerate all translation dictionaries for PrusaSlicer
-	    	// and try to match them with the system specific "preferred languages". 
-	    	// There seems to be a support for that on Windows and OSX, while on Linuxes the code just returns wxLocale::GetSystemLanguage().
-	    	// The last parameter gets added to the list of detected dictionaries. This is a workaround 
-	    	// for not having the English dictionary. Let's hope wxWidgets of various versions process this call the same way.
-			wxString best_language = wxTranslations::Get()->GetBestTranslation(SLIC3R_APP_KEY, wxLANGUAGE_ENGLISH);
-			if (! best_language.IsEmpty()) {
-				m_language_info_best = wxLocale::FindLanguageInfo(best_language);
-	        	BOOST_LOG_TRIVIAL(trace) << boost::format("Best translation language detected (may be different from user locales): %1%") % m_language_info_best->CanonicalName.ToUTF8().data();
-			}
+        wxTranslations *wx_trp = wxTranslations::Get();
+        if (wx_trp) {
+	    	    wxTranslations::Get()->SetLanguage(wxLANGUAGE_DEFAULT);
+	    	    // Let the wxFileTranslationsLoader enumerate all translation dictionaries for PrusaSlicer
+	    	    // and try to match them with the system specific "preferred languages". 
+	    	    // There seems to be a support for that on Windows and OSX, while on Linuxes the code just returns wxLocale::GetSystemLanguage().
+	    	    // The last parameter gets added to the list of detected dictionaries. This is a workaround 
+	    	    // for not having the English dictionary. Let's hope wxWidgets of various versions process this call the same way.
+			      wxString best_language = wxTranslations::Get()->GetBestTranslation(SLIC3R_APP_KEY, wxLANGUAGE_ENGLISH);
+			      if (! best_language.IsEmpty()) {
+				        m_language_info_best = wxLocale::FindLanguageInfo(best_language);
+	        	    BOOST_LOG_TRIVIAL(trace) << boost::format("Best translation language detected (may be different from user locales): %1%") % m_language_info_best->CanonicalName.ToUTF8().data();
+			      }
+        }
             #ifdef __linux__
             wxString lc_all;
             if (wxGetEnv("LC_ALL", &lc_all) && ! lc_all.IsEmpty()) {
@@ -2096,6 +2099,7 @@ bool GUI_App::load_language(wxString language, bool in
             }
             #endif
 		}
+		m_language_info_best = nullptr;
     }
 
 	const wxLanguageInfo *language_info = language.empty() ? nullptr : wxLocale::FindLanguageInfo(language);
