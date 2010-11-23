--- ./Modules/FindQt4.cmake.orig	2010-11-03 22:58:27.000000000 +0300
+++ ./Modules/FindQt4.cmake	2010-11-23 18:09:33.486039056 +0300
@@ -461,7 +461,7 @@
 # check for qmake
 # Debian uses qmake-qt4
 # macports' Qt uses qmake-mac
-FIND_PROGRAM(QT_QMAKE_EXECUTABLE NAMES qmake qmake4 qmake-qt4 qmake-mac PATHS
+FIND_PROGRAM(QT_QMAKE_EXECUTABLE NAMES qmake-qt4 qmake qmake4 qmake-mac PATHS
   "[HKEY_CURRENT_USER\\Software\\Trolltech\\Qt3Versions\\4.0.0;InstallDir]/bin"
   "[HKEY_CURRENT_USER\\Software\\Trolltech\\Versions\\4.0.0;InstallDir]/bin"
   "[HKEY_CURRENT_USER\\Software\\Trolltech\\Versions\\${qt_install_version};InstallDir]/bin"
@@ -705,13 +705,7 @@
   # ask qmake for the plugins directory
   IF (QT_LIBRARY_DIR AND NOT QT_PLUGINS_DIR  OR  QT_QMAKE_CHANGED)
     _qt4_query_qmake(QT_INSTALL_PLUGINS qt_plugins_dir)
-    SET(QT_PLUGINS_DIR NOTFOUND)
-    foreach(qt_cross_path ${CMAKE_FIND_ROOT_PATH})
-      set(qt_cross_paths ${qt_cross_paths} "${qt_cross_path}/plugins")
-    endforeach(qt_cross_path)
-    FIND_PATH(QT_PLUGINS_DIR NAMES accessible imageformats sqldrivers codecs designer
-      HINTS ${qt_cross_paths} ${qt_plugins_dir}
-      DOC "The location of the Qt plugins")
+    SET(QT_PLUGINS_DIR ${qt_plugins_dir} CACHE PATH "The location of the Qt plugins" FORCE)
   ENDIF (QT_LIBRARY_DIR AND NOT QT_PLUGINS_DIR  OR  QT_QMAKE_CHANGED)
 
   # ask qmake for the translations directory
