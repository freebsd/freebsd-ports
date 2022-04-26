--- cmake/Libraries.cmake.orig	2022-04-25 13:11:06 +0200
+++ cmake/Libraries.cmake
@@ -124,11 +124,9 @@
 elseif(UNIX)
 	find_package(PkgConfig REQUIRED)
 
-	if(LINUX)
-		pkg_check_modules(UDEV IMPORTED_TARGET libudev)
-		if(NOT TARGET PkgConfig::UDEV)
-			message(STATUS "Hardware detection disabled - Missing libudev")
-		endif()
+	pkg_check_modules(UDEV IMPORTED_TARGET libudev)
+	if(NOT TARGET PkgConfig::UDEV)
+		message(STATUS "Hardware detection disabled - Missing libudev")
 	endif()
 
 	pkg_check_modules(PCSC REQUIRED libpcsclite)
