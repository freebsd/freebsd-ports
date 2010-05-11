--- ./Modules/FindQt4.cmake.orig	2010-03-16 23:29:30.000000000 +0300
+++ ./Modules/FindQt4.cmake	2010-03-26 22:48:58.291402760 +0300
@@ -392,7 +392,7 @@
 # check for qmake
 # Debian uses qmake-qt4
 # macports' Qt uses qmake-mac
-FIND_PROGRAM(QT_QMAKE_EXECUTABLE NAMES qmake qmake4 qmake-qt4 qmake-mac PATHS
+FIND_PROGRAM(QT_QMAKE_EXECUTABLE NAMES qmake-qt4 qmake qmake4 qmake-mac PATHS
   "[HKEY_CURRENT_USER\\Software\\Trolltech\\Qt3Versions\\4.0.0;InstallDir]/bin"
   "[HKEY_CURRENT_USER\\Software\\Trolltech\\Versions\\4.0.0;InstallDir]/bin"
   "[HKEY_CURRENT_USER\\Software\\Trolltech\\Versions\\${qt_install_version};InstallDir]/bin"
