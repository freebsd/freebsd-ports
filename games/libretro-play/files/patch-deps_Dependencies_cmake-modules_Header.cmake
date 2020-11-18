--- deps/Dependencies/cmake-modules/Header.cmake.orig	2020-07-29 22:03:00 UTC
+++ deps/Dependencies/cmake-modules/Header.cmake
@@ -31,8 +31,8 @@ if(CMAKE_CURRENT_SOURCE_DIR STREQUAL "${CMAKE_SOURCE_D
 
 	endif()
 	
-	set(CMAKE_CXX_STANDARD 17)
-	set(CMAKE_CXX_STANDARD_REQUIRED ON)
+	
+	
 	if(TARGET_PLATFORM_WIN32)
 		set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /EHsc /MP")
 	endif()
