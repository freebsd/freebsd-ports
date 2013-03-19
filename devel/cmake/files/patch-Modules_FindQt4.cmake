--- Modules/FindQt4.cmake.orig	2012-11-06 21:41:36.000000000 +0200
+++ Modules/FindQt4.cmake	2012-11-27 22:31:37.000000000 +0200
@@ -497,7 +497,7 @@
 # check for qmake
 # Debian uses qmake-qt4
 # macports' Qt uses qmake-mac
-find_program(QT_QMAKE_EXECUTABLE NAMES qmake qmake4 qmake-qt4 qmake-mac
+find_program(QT_QMAKE_EXECUTABLE NAMES qmake-qt4 qmake qmake4 qmake-mac
   PATHS
     ENV QTDIR
     "[HKEY_CURRENT_USER\\Software\\Trolltech\\Versions\\${qt_install_version};InstallDir]"
@@ -690,13 +690,7 @@
   # ask qmake for the plugins directory
   if (QT_LIBRARY_DIR AND NOT QT_PLUGINS_DIR  OR  QT_QMAKE_CHANGED)
     _qt4_query_qmake(QT_INSTALL_PLUGINS qt_plugins_dir)
-    set(QT_PLUGINS_DIR NOTFOUND)
-    foreach(qt_cross_path ${CMAKE_FIND_ROOT_PATH})
-      set(qt_cross_paths ${qt_cross_paths} "${qt_cross_path}/plugins")
-    endforeach()
-    find_path(QT_PLUGINS_DIR NAMES accessible imageformats sqldrivers codecs designer
-      HINTS ${qt_cross_paths} ${qt_plugins_dir}
-      DOC "The location of the Qt plugins")
+    set(QT_PLUGINS_DIR ${qt_plugins_dir} CACHE PATH "The location of the Qt plugins" FORCE)
   endif ()
 
   # ask qmake for the translations directory
@@ -709,15 +703,7 @@
   if (QT_LIBRARY_DIR AND NOT QT_IMPORTS_DIR OR QT_QMAKE_CHANGED)
     _qt4_query_qmake(QT_INSTALL_IMPORTS qt_imports_dir)
     if(qt_imports_dir)
-      set(QT_IMPORTS_DIR NOTFOUND)
-      foreach(qt_cross_path ${CMAKE_FIND_ROOT_PATH})
-        set(qt_cross_paths ${qt_cross_paths} "${qt_cross_path}/imports")
-      endforeach()
-      find_path(QT_IMPORTS_DIR NAMES Qt
-        HINTS ${qt_cross_paths} ${qt_imports_dir}
-        DOC "The location of the Qt imports"
-        NO_CMAKE_PATH NO_CMAKE_ENVIRONMENT_PATH NO_SYSTEM_ENVIRONMENT_PATH
-        NO_CMAKE_SYSTEM_PATH)
+      set(QT_IMPORTS_DIR ${qt_imports_dir} CACHE PATH "The location of the Qt imports" FORCE)
       mark_as_advanced(QT_IMPORTS_DIR)
     endif()
   endif ()
