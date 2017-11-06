--- UniversalIndentGUI.pro.orig	2017-01-20 10:40:58 UTC
+++ UniversalIndentGUI.pro
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
