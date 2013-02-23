--- ./src/UiGuiSettings.cpp.orig	2013-02-17 16:32:05.000000000 +0100
+++ ./src/UiGuiSettings.cpp	2013-02-17 16:34:46.000000000 +0100
@@ -181,7 +181,7 @@
     _qsettings->setValue( "UniversalIndentGUI/language", _availableTranslations.indexOf( _qsettings->value("UniversalIndentGUI/language", "").toString() ) );
 
     // Read the update check settings from the settings file.
-    _qsettings->setValue( "UniversalIndentGUI/CheckForUpdate", _qsettings->value("UniversalIndentGUI/CheckForUpdate", true) );
+    _qsettings->setValue( "UniversalIndentGUI/CheckForUpdate", _qsettings->value("UniversalIndentGUI/CheckForUpdate", false) );
     _qsettings->setValue( "UniversalIndentGUI/LastUpdateCheck", _qsettings->value("UniversalIndentGUI/LastUpdateCheck", QDate(1900,1,1)) );
 
     // Read the main window state.
