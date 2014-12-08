--- cmake/Unix.cmake.orig	2014-11-11 12:00:55.000000000 +0000
+++ cmake/Unix.cmake	2014-12-05 08:24:29.222613898 +0000
@@ -34,17 +34,15 @@
 endif(NOT EXIV2_FOUND)
 
 # search for opencv
-unset(OpenCV_FOUND CACHE)
+unset(OPENCVCORE_FOUND CACHE)
 if(ENABLE_OPENCV)
-	find_package(OpenCV 2.1.0 REQUIRED core imgproc)
-	if (NOT OpenCV_LIBRARIES) # OpenCV_FOUND can not be used since it is set in Ubuntu 12.04 (without finding opencv)
-		# Older OpenCV versions only supplied pkg-config files
-		if(PKG_CONFIG_FOUND)
-			pkg_check_modules(OpenCV opencv>=2.1.0)
-		endif()
+	find_package(OpenCVCore COMPONENTS core imgproc REQUIRED)
+
+	if (NOT OPENCV_CORE_LIBRARY)
+		message(FATAL_ERROR "OpenCV libraries not found, but requested.")
 	endif()
 
-	if(NOT OpenCV_FOUND)
+	if (NOT OPENCVCORE_FOUND)
 		message(FATAL_ERROR "OpenCV not found, but requested.")
 	endif()
 
@@ -56,7 +54,7 @@
 
 # search for libraw
 if(ENABLE_RAW)
-	if(NOT OpenCV_FOUND)
+	if(NOT OPENCVCORE_FOUND)
 		message(FATAL_ERROR "OpenCV is mandotory when enabling RAW. You have to enable ENABLE_OPENCV")
 	endif()
 
@@ -72,7 +70,7 @@
 unset(TIFF_INCLUDE_DIR CACHE)
 unset(TIFF_LIBRARY CACHE)
 if(ENABLE_TIFF)
-	if(NOT OpenCV_FOUND)
+	if(NOT OPENCVCORE_FOUND)
 		message(FATAL_ERROR "OpenCV is mandotory when enabling TIFF. You have to enable ENABLE_OPENCV")
 	endif()
 	find_package(TIFF)
@@ -84,6 +82,9 @@
 	endif()
 endif(ENABLE_TIFF)
 
+# sysinfo library
+FIND_LIBRARY(SYSINFO_LIBRARY NAMES sysinfo)
+
 #search for quazip
 unset(QUAZIP_SOURCE_DIRECTORY CACHE)
 unset(QUAZIP_INCLUDE_DIRECTORY CACHE)
