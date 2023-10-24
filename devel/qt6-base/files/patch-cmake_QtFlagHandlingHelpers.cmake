--- cmake/QtFlagHandlingHelpers.cmake.orig	2023-09-21 19:24:26 UTC
+++ cmake/QtFlagHandlingHelpers.cmake
@@ -103,6 +103,10 @@ function(qt_internal_add_link_flags_no_undefined targe
             set(no_undefined_flag "-Wl,--no-undefined")
         endif()
 
+        if (CMAKE_SYSTEM_NAME MATCHES "FreeBSD")
+             set(no_undefined_flag "")
+        endif()
+
         set(CMAKE_REQUIRED_LINK_OPTIONS ${previous_CMAKE_REQUIRED_LINK_OPTIONS})
 
         if (NOT HAVE_DASH_UNDEFINED_SYMBOLS AND NOT HAVE_DASH_DASH_NO_UNDEFINED)
