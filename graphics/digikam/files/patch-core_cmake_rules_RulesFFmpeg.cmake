FFmpeg is only needed for the optional Media Player. Don't try to find it
otherwise. RulesFFmpeg was split out from RulesMediaPlayer in [1], but was
not blocked in the ENABLE_MEDIAPLAYER conditional that it was previously
under, making FFmpeg unconditionally required.

[1] https://invent.kde.org/graphics/digikam/-/commit/44da06a0b008eb4030ae59e57c11a1341c157c8c

--- core/cmake/rules/RulesFFmpeg.cmake.orig	2024-03-16 04:40:45 UTC
+++ core/cmake/rules/RulesFFmpeg.cmake
@@ -4,6 +4,8 @@
 # SPDX-License-Identifier: BSD-3-Clause
 #
 
+if(ENABLE_MEDIAPLAYER)
+
 find_package(FFmpeg REQUIRED COMPONENTS AVCODEC
                                         AVDEVICE
                                         AVFILTER
@@ -105,3 +107,5 @@ endif()
     )
 
 endif()
+
+endif(ENABLE_MEDIAPLAYER)
