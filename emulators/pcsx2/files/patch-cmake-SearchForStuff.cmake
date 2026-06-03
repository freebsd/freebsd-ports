Backport [1] to fix build with Qt 6.10.

[1] https://github.com/PCSX2/pcsx2/commit/8dffc857079e942ca77b091486c20c3c6530e4ed

--- cmake/SearchForStuff.cmake.orig	2025-06-29 19:47:12 UTC
+++ cmake/SearchForStuff.cmake
@@ -1,6 +1,8 @@
 #-------------------------------------------------------------------------------
 #                       Search all libraries on the system
 #-------------------------------------------------------------------------------
+list(APPEND CMAKE_MODULE_PATH ${CMAKE_LOCALBASE}/lib/cmake/SDL3_ttf)
+include(PkgConfigHelper)
 find_package(Git)
 
 # Require threads on all OSes.
@@ -108,6 +110,10 @@ find_package(Qt6 6.7.3 COMPONENTS CoreTools Core GuiTo
 
 # Find the Qt components that we need.
 find_package(Qt6 6.7.3 COMPONENTS CoreTools Core GuiTools Gui WidgetsTools Widgets LinguistTools REQUIRED)
+
+if(Qt6_VERSION VERSION_GREATER_EQUAL 6.10.0)
+	find_package(Qt6 COMPONENTS GuiPrivate REQUIRED)
+endif()
 
 if(WIN32)
   add_subdirectory(3rdparty/rainterface EXCLUDE_FROM_ALL)
