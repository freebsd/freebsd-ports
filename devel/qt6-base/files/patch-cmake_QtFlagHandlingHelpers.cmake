--- cmake/QtFlagHandlingHelpers.cmake.orig	2023-11-15 13:58:42 UTC
+++ cmake/QtFlagHandlingHelpers.cmake
@@ -132,6 +132,10 @@ function(qt_internal_add_link_flags_no_undefined targe
             set(no_undefined_flag "-Wl,--no-undefined")
         endif()
 
+        if (CMAKE_SYSTEM_NAME MATCHES "FreeBSD")
+             set(no_undefined_flag "")
+        endif()
+
         set(CMAKE_REQUIRED_LINK_OPTIONS ${previous_CMAKE_REQUIRED_LINK_OPTIONS})
 
         if (NOT HAVE_DASH_UNDEFINED_SYMBOLS AND NOT HAVE_DASH_DASH_NO_UNDEFINED)
