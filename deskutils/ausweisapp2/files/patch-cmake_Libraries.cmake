--- cmake/Libraries.cmake.orig	2022-09-06 11:32:26 UTC
+++ cmake/Libraries.cmake
@@ -144,7 +144,7 @@ elseif(MAC)
 	find_library(OSX_FOUNDATION Foundation)
 	find_library(OSX_SERVICEMANAGEMENT ServiceManagement)
 elseif(UNIX)
-	if(LINUX)
+	if(LINUX OR BSD)
 		find_package(PkgConfig REQUIRED)
 		pkg_check_modules(UDEV IMPORTED_TARGET libudev)
 		if(NOT TARGET PkgConfig::UDEV)
