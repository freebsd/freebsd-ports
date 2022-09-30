--- cmake/QtRpathHelpers.cmake.orig	2022-09-19 10:23:04 UTC
+++ cmake/QtRpathHelpers.cmake
@@ -5,6 +5,8 @@ function(qt_internal_get_relative_rpath_base_token out
         set(rpath_rel_base "@loader_path")
     elseif(LINUX OR SOLARIS OR FREEBSD OR HURD)
         set(rpath_rel_base "$ORIGIN")
+    elseif(CMAKE_SYSTEM_NAME MATCHES "FreeBSD")
+        set(rpath_rel_base "$ORIGIN")
     else()
         set(rpath_rel_base "NO_KNOWN_RPATH_REL_BASE")
     endif()
