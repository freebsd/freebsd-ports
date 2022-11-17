--- src/slic3r/GUI/GUI_App.cpp.orig	2022-09-06 07:09:19 UTC
+++ src/slic3r/GUI/GUI_App.cpp
@@ -2072,7 +2072,7 @@ bool GUI_App::load_language(wxString language, bool in
 	        	BOOST_LOG_TRIVIAL(trace) << boost::format("System language detected (user locales and such): %1%") % m_language_info_system->CanonicalName.ToUTF8().data();
 	        }
 		}
-        {
+        if (0) {
 	    	// Allocating a temporary locale will switch the default wxTranslations to its internal wxTranslations instance.
 	    	wxLocale temp_locale;
 	    	// Set the current translation's language to default, otherwise GetBestTranslation() may not work (see the wxWidgets source code).
@@ -2096,6 +2096,7 @@ bool GUI_App::load_language(wxString language, bool in
             }
             #endif
 		}
+		m_language_info_best = nullptr;
     }
 
 	const wxLanguageInfo *language_info = language.empty() ? nullptr : wxLocale::FindLanguageInfo(language);
