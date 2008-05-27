--- ./Modules/FindQt4.cmake.orig	2008-01-21 19:59:51.000000000 +0100
+++ ./Modules/FindQt4.cmake	2008-04-25 21:45:15.000000000 +0200
@@ -250,7 +250,7 @@
 
 GET_FILENAME_COMPONENT(qt_install_version "[HKEY_CURRENT_USER\\Software\\trolltech\\Versions;DefaultQtVersion]" NAME)
 # check for qmake
-FIND_PROGRAM(QT_QMAKE_EXECUTABLE NAMES qmake qmake4 qmake-qt4 PATHS
+FIND_PROGRAM(QT_QMAKE_EXECUTABLE NAMES qmake-qt4 qmake4 qmake PATHS
   "[HKEY_CURRENT_USER\\Software\\Trolltech\\Qt3Versions\\4.0.0;InstallDir]/bin"
   "[HKEY_CURRENT_USER\\Software\\Trolltech\\Versions\\4.0.0;InstallDir]/bin"
   "[HKEY_CURRENT_USER\\Software\\Trolltech\\Versions\\${qt_install_version};InstallDir]/bin"
@@ -790,9 +790,9 @@
     "${QT_UIC_EXECUTABLE_INTERNAL}" QT_UIC_EXECUTABLE_INTERNAL)
 
   SET(QT_MOC_EXECUTABLE 
-    ${QT_MOC_EXECUTABLE_INTERNAL} CACHE FILEPATH "The moc executable")
+    ${QT_MOC_EXECUTABLE_INTERNAL} CACHE FILEPATH "The moc executable" FORCE)
   SET(QT_UIC_EXECUTABLE 
-    ${QT_UIC_EXECUTABLE_INTERNAL} CACHE FILEPATH "The uic executable")
+    ${QT_UIC_EXECUTABLE_INTERNAL} CACHE FILEPATH "The uic executable" FORCE)
 
   FIND_PROGRAM(QT_UIC3_EXECUTABLE
     NAMES uic3
