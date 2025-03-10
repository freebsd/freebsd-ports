--- settings.cpp.orig	2023-08-27 20:32:18 UTC
+++ settings.cpp
@@ -177,9 +177,9 @@ void settings::setDefaultSettings(QSettings& settings)
     // Add system font to CorePad, CoreTerminal
     QFont monoFont = QFontDatabase::systemFont(QFontDatabase::FixedFont);
     if ( not monoFont.family().count() ) {
-        monoFont = QFont("monospace", 9);}
+        monoFont = QFont("monospace", 12);}
     if (monoFont.styleHint() != QFont::Monospace) {
-        monoFont = QFont("monospace", 9);}
+        monoFont = QFont("monospace", 12);}
 
     // CorePad
     if (!settings.contains("CorePad/Font")) {
