--- settings.cpp.orig	2021-08-19 22:05:32 UTC
+++ settings.cpp
@@ -75,13 +75,13 @@ void settings::setDefaultSettings()
     QFont genFont = QFontDatabase::systemFont(QFontDatabase::GeneralFont);
     QFont monoFont = QFontDatabase::systemFont(QFontDatabase::FixedFont);
     if ( not genFont.family().count() )
-        genFont = QFont("Cantarell", 9);
+        genFont = QFont("Cantarell", 12);
 
     if ( not monoFont.family().count() )
-        monoFont = QFont("monospace", 9);
+        monoFont = QFont("monospace", 12);
 
     if (monoFont.styleHint() != QFont::Monospace) {
-        monoFont = QFont("monospace", 9);
+        monoFont = QFont("monospace", 12);
     }
 
 	// CoreAction
