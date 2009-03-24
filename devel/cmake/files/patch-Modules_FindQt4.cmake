--- ./Modules/FindQt4.cmake.orig	2009-02-21 23:36:50.000000000 +0300
+++ ./Modules/FindQt4.cmake	2009-03-20 13:20:18.000000000 +0300
@@ -319,7 +319,7 @@
 
 GET_FILENAME_COMPONENT(qt_install_version "[HKEY_CURRENT_USER\\Software\\trolltech\\Versions;DefaultQtVersion]" NAME)
 # check for qmake
-FIND_PROGRAM(QT_QMAKE_EXECUTABLE NAMES qmake qmake4 qmake-qt4 PATHS
+FIND_PROGRAM(QT_QMAKE_EXECUTABLE NAMES qmake-qt4 qmake4 qmake PATHS
   "[HKEY_CURRENT_USER\\Software\\Trolltech\\Qt3Versions\\4.0.0;InstallDir]/bin"
   "[HKEY_CURRENT_USER\\Software\\Trolltech\\Versions\\4.0.0;InstallDir]/bin"
   "[HKEY_CURRENT_USER\\Software\\Trolltech\\Versions\\${qt_install_version};InstallDir]/bin"
@@ -855,13 +855,13 @@
     )
 
   FIND_PROGRAM(QT_LUPDATE_EXECUTABLE
-    NAMES lupdate
+    NAMES lupdate-qt4
     PATHS ${QT_BINARY_DIR}
     NO_DEFAULT_PATH
     )
 
   FIND_PROGRAM(QT_LRELEASE_EXECUTABLE
-    NAMES lrelease
+    NAMES lrelease-qt4
     PATHS ${QT_BINARY_DIR}
     NO_DEFAULT_PATH
     )
