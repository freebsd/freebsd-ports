--- settings.cpp.orig	2022-06-04 12:07:40 UTC
+++ settings.cpp
@@ -85,10 +85,10 @@ void settings::setDefaultSettings()
     QFont monoFont = QFontDatabase::systemFont(QFontDatabase::FixedFont);
 
     if ( not monoFont.family().count() )
-        monoFont = QFont("monospace", 9);
+        monoFont = QFont("monospace", 12);
 
     if (monoFont.styleHint() != QFont::Monospace) {
-        monoFont = QFont("monospace", 9);
+        monoFont = QFont("monospace", 12);
     }
 
 
