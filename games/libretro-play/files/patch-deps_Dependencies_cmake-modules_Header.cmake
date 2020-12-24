--- deps/Dependencies/cmake-modules/Header.cmake.orig	2020-07-29 22:03:00 UTC
+++ deps/Dependencies/cmake-modules/Header.cmake
@@ -27,12 +27,15 @@ if(CMAKE_CURRENT_SOURCE_DIR STREQUAL "${CMAKE_SOURCE_D
 		if (${CMAKE_SYSTEM_PROCESSOR} MATCHES "^(aarch64.*|AARCH64.*)")
 			message("-- Arch: aarch64 --")
 			set(TARGET_PLATFORM_UNIX_AARCH64 TRUE)
+		elseif(${CMAKE_SYSTEM_PROCESSOR} MATCHES "^(ppc64.*|powerpc64.*)")
+			message("-- Arch: powerpc64 --")
+			set(TARGET_PLATFORM_UNIX_POWERPC64 TRUE)
 		endif()
 
 	endif()
 	
-	set(CMAKE_CXX_STANDARD 17)
-	set(CMAKE_CXX_STANDARD_REQUIRED ON)
+	
+	
 	if(TARGET_PLATFORM_WIN32)
 		set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /EHsc /MP")
 	endif()
