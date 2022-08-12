--- cmake/QtRpathHelpers.cmake.orig	2022-05-25 08:58:52 UTC
+++ cmake/QtRpathHelpers.cmake
@@ -29,6 +29,8 @@ function(qt_compute_relative_rpath_base rpath install_
         set(rpath_rel_base "@loader_path")
     elseif(LINUX OR SOLARIS OR FREEBSD)
         set(rpath_rel_base "$ORIGIN")
+    elseif(CMAKE_SYSTEM_NAME MATCHES "FreeBSD")
+        set(rpath_rel_base "$ORIGIN")
     else()
         message(WARNING "No known RPATH_REL_BASE for target platform.")
         set(rpath_rel_base "NO_KNOWN_RPATH_REL_BASE")
