--- cmake/wxWidgets.cmake.orig	2016-03-09 20:19:17 UTC
+++ cmake/wxWidgets.cmake
@@ -15,21 +15,16 @@ IF(WIN32)
 ELSE()
     SET(wxWidgets_USE_UNICODE ON)
     SET(wxWidgets_USE_UNIVERSAL ON)
-    IF(CMAKE_BUILD_TYPE STREQUAL "Debug")
-        SET(wxWidgets_USE_DEBUG ON)
-        SET(wxWidgets_USE_STATIC OFF)
-        MESSAGE(STATUS "Using debug version of wxWidgets")
-    ELSE()
-        SET(wxWidgets_USE_DEBUG OFF)
-        SET(wxWidgets_USE_STATIC ON)
-        MESSAGE(STATUS "Using static wxWidgets library")
-    ENDIF()
+    SET(wxWidgets_USE_DEBUG OFF)
+    SET(wxWidgets_USE_STATIC OFF)
+    MESSAGE(STATUS "Using dynamic wxWidgets library")
 ENDIF()
 
-SET(wxWidgets_FIND_COMPONENTS gl core base adv)
+#SET(wxWidgets_FIND_COMPONENTS gl core base adv)
+FIND_PACKAGE(wxWidgets 3.0 COMPONENTS gl core base adv)
 
-SET(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_SOURCE_DIR}/cmake/Modules/")
-FIND_PACKAGE(wxWidgetsTB REQUIRED)
+#SET(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_SOURCE_DIR}/cmake/Modules/")
+#FIND_PACKAGE(wxWidgetsTB REQUIRED)
 INCLUDE("${wxWidgets_USE_FILE}")
 
 # Remove QuickTime framework on OS X; it's not needed and produces a linker warning
