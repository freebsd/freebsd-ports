--- UniversalIndentGUI.pro.orig	2018-02-16 21:30:56 UTC
+++ UniversalIndentGUI.pro
@@ -23,7 +23,7 @@ macx {
  ICON = resources/UniversalIndentGUI.icns
 }
 else {
- LIBS += -lqscintilla2
+ LIBS += -lqscintilla2_qt4
 }
 
 CONFIG(release, debug|release) {
@@ -37,10 +37,10 @@ macx:pipe2nul = "&> /dev/null"
 ##########################
 message(Updating language files)
 lupdate = lupdate
-unix:lupdate = lupdate-qt4
+unix:lupdate = lupdate
 macx:lupdate = lupdate
 lrelease = lrelease
-unix:lrelease = lrelease-qt4
+unix:lrelease = lrelease
 macx:lrelease = lrelease
 # Update translation files
 message ( Updating universalindent.ts )
