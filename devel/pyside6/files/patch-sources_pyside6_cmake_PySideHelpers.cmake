Find required packages before testing whether they are FOUND.

--- sources/pyside6/cmake/PySideHelpers.cmake.orig	2024-10-09 13:33:59 UTC
+++ sources/pyside6/cmake/PySideHelpers.cmake
@@ -132,6 +132,8 @@ macro(collect_optional_modules)
     list(APPEND ALL_OPTIONAL_MODULES WebChannel WebEngineCore WebEngineWidgets
          WebEngineQuick WebSockets HttpServer)
     # for Windows and Linux, QtWebView depends on QtWebEngine to render content
+    find_package(Qt${QT_MAJOR_VERSION}WebEngineCore)
+    find_package(Qt${QT_MAJOR_VERSION}WebEngineQuick)
     if ((WIN32 OR UNIX) AND NOT APPLE AND Qt${QT_MAJOR_VERSION}WebEngineCore_FOUND AND
         Qt${QT_MAJOR_VERSION}WebEngineQuick_FOUND)
         list(APPEND ALL_OPTIONAL_MODULES WebView)
