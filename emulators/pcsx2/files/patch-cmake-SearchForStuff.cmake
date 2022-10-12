Enable building with WX 3.1

--- cmake/SearchForStuff.cmake.orig	2022-09-02 10:21:30 UTC
+++ cmake/SearchForStuff.cmake
@@ -81,7 +81,12 @@ else()
 			endif()
 		else()
 			if (${CMAKE_SYSTEM_NAME} MATCHES "FreeBSD")
-				set(wxWidgets_CONFIG_EXECUTABLE "/usr/local/bin/wxgtk3u-3.0-config")
+				if(EXISTS "/usr/local/bin/wxgtk3u-3.1-config")
+					set(wxWidgets_CONFIG_EXECUTABLE "/usr/local/bin/wxgtk3u-3.1-config")
+				endif()
+				if(EXISTS "/usr/local/bin/wxgtk3u-3.0-config")
+					set(wxWidgets_CONFIG_EXECUTABLE "/usr/local/bin/wxgtk3u-3.0-config")
+				endif()
 			endif()
 			if(EXISTS "/usr/bin/wx-config-3.2")
 				set(wxWidgets_CONFIG_EXECUTABLE "/usr/bin/wx-config-3.2")
