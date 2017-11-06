--- Modules/FindQt4.cmake.orig	2017-05-31 14:00:09 UTC
+++ Modules/FindQt4.cmake
@@ -706,14 +706,7 @@ if (QT_QMAKE_EXECUTABLE AND
   # ask qmake for the plugins directory
   if (QT_LIBRARY_DIR AND NOT QT_PLUGINS_DIR  OR  QT_QMAKE_CHANGED)
     _qt4_query_qmake(QT_INSTALL_PLUGINS qt_plugins_dir)
-    set(QT_PLUGINS_DIR NOTFOUND)
-    foreach(qt_cross_path ${CMAKE_FIND_ROOT_PATH})
-      set(qt_cross_paths ${qt_cross_paths} "${qt_cross_path}/plugins")
-    endforeach()
-    find_path(QT_PLUGINS_DIR NAMES accessible imageformats sqldrivers codecs designer
-      HINTS ${qt_cross_paths} ${qt_plugins_dir}
-      DOC "The location of the Qt plugins"
-      NO_CMAKE_FIND_ROOT_PATH)
+    set(QT_PLUGINS_DIR ${qt_plugins_dir} CACHE PATH "The location of the Qt plugins" FORCE)
   endif ()
 
   # ask qmake for the translations directory
@@ -726,16 +719,7 @@ if (QT_QMAKE_EXECUTABLE AND
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
-        NO_CMAKE_FIND_ROOT_PATH
-        NO_CMAKE_PATH NO_CMAKE_ENVIRONMENT_PATH NO_SYSTEM_ENVIRONMENT_PATH
-        NO_CMAKE_SYSTEM_PATH)
+      set(QT_IMPORTS_DIR ${qt_imports_dir} CACHE PATH "The location of the Qt imports" FORCE)
       mark_as_advanced(QT_IMPORTS_DIR)
     endif()
   endif ()
