--- cmake/LocationsPostPorts.cmake.orig	2026-07-01 22:22:28 UTC
+++ cmake/LocationsPostPorts.cmake
@@ -17,7 +17,7 @@ if(SWIPL_INSTALL_GENERIC_BUNDLE)
   endif()
   set(SWIPL_INSTALL_MANPAGES share/man/man1
       CACHE STRING "Directory for man pages")
-  set(SWIPL_INSTALL_PKGCONFIG share/pkgconfig
+  set(SWIPL_INSTALL_PKGCONFIG libdata/pkgconfig
       CACHE STRING "Directory for pkg-config pages")
 endif()
 
