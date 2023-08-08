--- build/cmake/FindQt5.cmake.orig	2023-07-14 09:53:57 UTC
+++ build/cmake/FindQt5.cmake
@@ -2,7 +2,7 @@
 include(GetUtilsFunctions) # library of CMake functions ("fn__" namespace)
 
 # Print Qt version or fail the build if Qt (qmake) is not in PATH.
-fn__require_program(QMAKE Qt --version "https://musescore.org/en/handbook/developers-handbook/compilation" qmake)
+fn__require_program(QMAKE Qt --version "https://musescore.org/en/handbook/developers-handbook/compilation" qmake-qt5)
 
 set(CMAKE_AUTOUIC ON)
 set(CMAKE_AUTOMOC ON)
@@ -41,7 +41,7 @@ if (WIN32)
       )
 endif(WIN32)
 
-if (OS_IS_LIN)
+if (TRUE)
     set(_components
       ${_components}
       DBus
@@ -52,9 +52,13 @@ find_package(Qt5Core ${QT_MIN_VERSION} REQUIRED)
 
 foreach(_component ${_components})
   find_package(Qt5${_component})
-  list(APPEND QT_LIBRARIES ${Qt5${_component}_LIBRARIES})
-  list(APPEND QT_INCLUDES ${Qt5${_component}_INCLUDE_DIRS})
-  add_definitions(${Qt5${_component}_DEFINITIONS})
+  if(NOT Qt5${_component}_FOUND)
+    message(STATUS "Missing component ${_component}")
+  else()
+    list(APPEND QT_LIBRARIES ${Qt5${_component}_LIBRARIES})
+    list(APPEND QT_INCLUDES ${Qt5${_component}_INCLUDE_DIRS})
+    add_definitions(${Qt5${_component}_DEFINITIONS})
+  endif()
 endforeach()
 
 include_directories(${QT_INCLUDES})
@@ -89,3 +93,4 @@ foreach(_var ${_qmake_vars})
 endforeach(_var)
 
 #add_definitions(-DQT_DISABLE_DEPRECATED_BEFORE=0)
+set(Qt5_FOUND ON)
