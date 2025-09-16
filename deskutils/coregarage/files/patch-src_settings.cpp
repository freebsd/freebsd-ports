--- src/settings.cpp.orig	2025-09-13 11:52:38 UTC
+++ src/settings.cpp
@@ -177,9 +177,9 @@ void settings::setDefaultSettings(QSettings& settings)
     // Add system font to CorePad, CoreTerminal
     QFont monoFont = QFontDatabase::systemFont(QFontDatabase::FixedFont);
     if ( not monoFont.family().length() ) {
-        monoFont = QFont("monospace", 9);}
+        monoFont = QFont("monospace", 12);}
     if (monoFont.styleHint() != QFont::Monospace) {
-        monoFont = QFont("monospace", 9);}
+        monoFont = QFont("monospace", 12);}
 
     // CorePad
     if (!settings.contains("CorePad/Font")) {
