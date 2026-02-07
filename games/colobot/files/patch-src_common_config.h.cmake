--- src/common/config.h.cmake.orig	2021-12-03 23:29:13 UTC
+++ src/common/config.h.cmake
@@ -2,6 +2,7 @@
 
 // Macros set by CMake
 #cmakedefine PLATFORM_WINDOWS @PLATFORM_WINDOWS@
+#cmakedefine PLATFORM_FREEBSD @PLATFORM_FREEBSD@
 #cmakedefine PLATFORM_LINUX @PLATFORM_LINUX@
 #cmakedefine PLATFORM_GNU @PLATFORM_GNU@
 #cmakedefine PLATFORM_MACOSX @PLATFORM_MACOSX@
