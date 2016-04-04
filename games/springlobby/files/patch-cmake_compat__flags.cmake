--- cmake/compat_flags.cmake.orig	2013-11-22 21:34:04 UTC
+++ cmake/compat_flags.cmake
@@ -4,7 +4,6 @@ execute_process(COMMAND ${CMAKE_C_COMPIL
 
 # try to use compiler flag -std=c++11
 MACRO(AddSTDFlag FLAG)
-	set(CMAKE_REQUIRED_FLAGS "${CMAKE_REQUIRED_FLAGS} ${FLAG} ")
 	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${FLAG} ")
 	set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} ${FLAG} ")
 	set(CMAKE_CXX_FLAGS_MINSIZEREL "${CMAKE_CXX_FLAGS_MINSIZEREL} ${FLAG} ")
