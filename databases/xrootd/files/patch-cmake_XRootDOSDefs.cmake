--- cmake/XRootDOSDefs.cmake.orig	2024-03-31 18:44:16 UTC
+++ cmake/XRootDOSDefs.cmake
@@ -129,7 +129,7 @@ if( ${CMAKE_SYSTEM_NAME} STREQUAL "FreeBSD" )
 if( ${CMAKE_SYSTEM_NAME} STREQUAL "FreeBSD" )
   define_default( CMAKE_INSTALL_LIBDIR "lib" )
   define_default( CMAKE_INSTALL_BINDIR "bin" )
-  define_default( CMAKE_INSTALL_MANDIR "man" )
+  define_default( CMAKE_INSTALL_MANDIR "share/man" )
   define_default( CMAKE_INSTALL_INCLUDEDIR "include" )
   define_default( CMAKE_INSTALL_DATADIR "share" )
 endif()
