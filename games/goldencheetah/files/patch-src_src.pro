--- src/src.pro.orig	2017-01-18 19:54:38 UTC
+++ src/src.pro
@@ -725,7 +725,7 @@ TRANSLATIONS = translations/gc_fr.ts \
 
    isEmpty(QMAKE_LRELEASE) {
      win32:QMAKE_LRELEASE = $$[QT_INSTALL_BINS]\\lrelease.exe
-     unix:!macx {QMAKE_LRELEASE = $$[QT_INSTALL_BINS]/lrelease-qt4 }
+     unix:!macx {QMAKE_LRELEASE = $$[QT_INSTALL_BINS]/lrelease }
      else:QMAKE_LRELEASE = $$[QT_INSTALL_BINS]/lrelease
    }
 
