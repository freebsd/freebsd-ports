--- cmake/QtFlagHandlingHelpers.cmake.orig	2024-09-18 16:48:24 UTC
+++ cmake/QtFlagHandlingHelpers.cmake
@@ -177,6 +177,10 @@ function(qt_internal_add_link_flags_no_undefined targe
             set(no_undefined_flag "-Wl,--no-undefined")
         endif()
 
+        if (CMAKE_SYSTEM_NAME MATCHES "FreeBSD")
+             set(no_undefined_flag "")
+        endif()
+
         set(CMAKE_REQUIRED_LINK_OPTIONS ${previous_CMAKE_REQUIRED_LINK_OPTIONS})
 
         if (NOT HAVE_DASH_UNDEFINED_SYMBOLS AND NOT HAVE_DASH_DASH_NO_UNDEFINED)
