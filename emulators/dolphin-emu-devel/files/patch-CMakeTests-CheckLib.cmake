--- CMakeTests/CheckLib.cmake.orig	2012-11-07 08:05:26.000000000 +0100
+++ CMakeTests/CheckLib.cmake	2013-03-06 07:22:30.000000000 +0100
@@ -55,8 +55,8 @@
 
 macro(check_libav)
 	if(PKG_CONFIG_FOUND)
-		pkg_check_modules(LIBAV libavcodec>=53.35.0 libavformat>=53.21.0
-			libswscale>=2.1.0 libavutil>=51.22.1)
+		pkg_check_modules(LIBAV libavcodec1>=53.35.0 libavformat1>=53.21.0
+			libswscale1>=2.1.0 libavutil1>=51.22.1)
 	else()
 		message("pkg-config is required to check for libav")
 	endif()
@@ -64,6 +64,7 @@
 		message("libav found, enabling AVI frame dumps")
 		add_definitions(-DHAVE_LIBAV)
 		include_directories(${LIBAV_INCLUDE_DIRS})
+		link_directories(${LIBAV_LIBRARY_DIRS})
 	else()
 		message("libav not found, disabling AVI frame dumps")
 	endif()
