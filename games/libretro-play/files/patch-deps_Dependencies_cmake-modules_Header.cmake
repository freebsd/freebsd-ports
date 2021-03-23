--- deps/Dependencies/cmake-modules/Header.cmake.orig	2020-07-29 22:03:00 UTC
+++ deps/Dependencies/cmake-modules/Header.cmake
@@ -30,11 +30,12 @@
 		elseif(${CMAKE_SYSTEM_PROCESSOR} MATCHES "^arm")
 			message("-- Arch: arm --")
 			set(TARGET_PLATFORM_UNIX_ARM TRUE)
+		elseif(${CMAKE_SYSTEM_PROCESSOR} MATCHES "^(ppc64.*|powerpc64.*)")
+			message("-- Arch: powerpc64 --")
+			set(TARGET_PLATFORM_UNIX_POWERPC64 TRUE)
 		endif()
 	endif()
 	
-	set(CMAKE_CXX_STANDARD 17)
-	set(CMAKE_CXX_STANDARD_REQUIRED ON)
 	if(TARGET_PLATFORM_WIN32)
 		set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /EHsc /MP")
 	endif()
