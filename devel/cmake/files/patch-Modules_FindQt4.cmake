--- ./Modules/FindQt4.cmake.orig	2008-05-05 22:25:53.000000000 +0400
+++ ./Modules/FindQt4.cmake	2008-07-21 02:37:16.000000000 +0400
@@ -293,7 +293,7 @@
 
 GET_FILENAME_COMPONENT(qt_install_version "[HKEY_CURRENT_USER\\Software\\trolltech\\Versions;DefaultQtVersion]" NAME)
 # check for qmake
-FIND_PROGRAM(QT_QMAKE_EXECUTABLE NAMES qmake qmake4 qmake-qt4 PATHS
+FIND_PROGRAM(QT_QMAKE_EXECUTABLE NAMES qmake-qt4 qmake4 qmake PATHS
   "[HKEY_CURRENT_USER\\Software\\Trolltech\\Qt3Versions\\4.0.0;InstallDir]/bin"
   "[HKEY_CURRENT_USER\\Software\\Trolltech\\Versions\\4.0.0;InstallDir]/bin"
   "[HKEY_CURRENT_USER\\Software\\Trolltech\\Versions\\${qt_install_version};InstallDir]/bin"
@@ -915,9 +915,9 @@
     "${QT_UIC_EXECUTABLE_INTERNAL}" QT_UIC_EXECUTABLE_INTERNAL)
 
   SET(QT_MOC_EXECUTABLE 
-    ${QT_MOC_EXECUTABLE_INTERNAL} CACHE FILEPATH "The moc executable")
+    ${QT_MOC_EXECUTABLE_INTERNAL} CACHE FILEPATH "The moc executable" FORCE)
   SET(QT_UIC_EXECUTABLE 
-    ${QT_UIC_EXECUTABLE_INTERNAL} CACHE FILEPATH "The uic executable")
+    ${QT_UIC_EXECUTABLE_INTERNAL} CACHE FILEPATH "The uic executable" FORCE)
 
   FIND_PROGRAM(QT_UIC3_EXECUTABLE
     NAMES uic3
@@ -944,13 +944,13 @@
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
