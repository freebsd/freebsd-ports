--- Modules/FindQt4.cmake.orig	2018-03-28 11:16:49 UTC
+++ Modules/FindQt4.cmake
@@ -713,10 +713,15 @@ if (QT_QMAKE_EXECUTABLE AND
     foreach(qt_cross_path ${CMAKE_FIND_ROOT_PATH})
       set(qt_cross_paths ${qt_cross_paths} "${qt_cross_path}/plugins")
     endforeach()
-    find_path(QT_PLUGINS_DIR NAMES accessible imageformats sqldrivers codecs designer
+    find_path(QT_PLUGINS_DIR NAMES accessible imageformats sqldrivers codecs
       HINTS ${qt_cross_paths} ${qt_plugins_dir}
       DOC "The location of the Qt plugins"
-      NO_CMAKE_FIND_ROOT_PATH)
+      NO_CMAKE_FIND_ROOT_PATH
+      NO_SYSTEM_ENVIRONMENT_PATH
+      NO_CMAKE_SYSTEM_PATH)
+    if(NOT QT_PLUGINS_DIR AND qt_plugins_dir)
+      set(QT_PLUGINS_DIR ${qt_plugins_dir})
+    endif()
   endif ()
 
   # ask qmake for the translations directory
@@ -740,6 +745,9 @@ if (QT_QMAKE_EXECUTABLE AND
         NO_CMAKE_PATH NO_CMAKE_ENVIRONMENT_PATH NO_SYSTEM_ENVIRONMENT_PATH
         NO_CMAKE_SYSTEM_PATH)
       mark_as_advanced(QT_IMPORTS_DIR)
+      if(NOT QT_IMPORTS_DIR AND qt_imports_dir)
+        set(QT_IMPORTS_DIR ${qt_imports_dir})
+      endif()
     endif()
   endif ()
 
