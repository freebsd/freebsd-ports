--- Modules/FindQt4.cmake.orig	2009-05-10 21:46:40.000000000 +0200
+++ Modules/FindQt4.cmake	2009-05-10 21:47:58.000000000 +0200
@@ -336,7 +336,7 @@
 
 GET_FILENAME_COMPONENT(qt_install_version "[HKEY_CURRENT_USER\\Software\\trolltech\\Versions;DefaultQtVersion]" NAME)
 # check for qmake
-FIND_PROGRAM(QT_QMAKE_EXECUTABLE NAMES qmake qmake4 qmake-qt4 PATHS
+FIND_PROGRAM(QT_QMAKE_EXECUTABLE NAMES qmake-qt4 qmake4 qmake PATHS
   "[HKEY_CURRENT_USER\\Software\\Trolltech\\Qt3Versions\\4.0.0;InstallDir]/bin"
   "[HKEY_CURRENT_USER\\Software\\Trolltech\\Versions\\4.0.0;InstallDir]/bin"
   "[HKEY_CURRENT_USER\\Software\\Trolltech\\Versions\\${qt_install_version};InstallDir]/bin"
