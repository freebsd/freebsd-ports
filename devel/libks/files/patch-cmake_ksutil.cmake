--- cmake/ksutil.cmake.orig	2026-05-09 17:13:27 UTC
+++ cmake/ksutil.cmake
@@ -130,6 +130,18 @@ macro(ksutil_setup_platform)
 		set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
 		set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
 		set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
+	elseif (CMAKE_SYSTEM_NAME STREQUAL "FreeBSD")
+		message("Platform is FreeBSD")
+		set(KS_PLAT_FBSD 1 CACHE INTERNAL "Platform definition" FORCE)
+		set(CMAKE_POSITION_INDEPENDENT_CODE YES)
+
+		add_definitions("-DKS_PLAT_FBSD=1")
+		set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c11")
+
+		if (NOT CMAKE_INSTALL_PREFIX)
+			set(CMAKE_INSTALL_PREFIX "/usr/local" CACHE INTERNAL "Prefix prepended to install directories" FORCE)
+			set(CMAKE_PREFIX_PATH "/usr/local" CACHE INTERNAL "Prefix search path" FORCE)
+		endif()
 	else()
 		message("Platform is linux")
 		set(KS_PLAT_LIN 1 CACHE INTERNAL "Platform definition" FORCE)
