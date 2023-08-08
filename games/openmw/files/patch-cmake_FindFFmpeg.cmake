--- cmake/FindFFmpeg.cmake.orig	2023-04-24 10:57:53 UTC
+++ cmake/FindFFmpeg.cmake
@@ -33,6 +33,8 @@
 # Redistribution and use is allowed according to the terms of the BSD license.
 # For details see the accompanying COPYING-CMAKE-SCRIPTS file.
 
+set(CMAKE_PREFIX_PATH "%%LOCALBASE%%/ffmpeg4;%%LOCALBASE%%/ffmpeg4/libexec")
+
 include(LibFindMacros)
 include(FindPackageHandleStandardArgs)
 
