--- cmake/compilerFlags.cmake.orig	2020-07-09 11:24:28 UTC
+++ cmake/compilerFlags.cmake
@@ -26,7 +26,11 @@ if ( MINGW OR UNIX OR MSYS ) # MINGW, Linux, APPLE, CY
         # This fails under Fedora, MinGW GCC 8.3.0 and CYGWIN/MSYS 9.3.0
         if (NOT (MINGW OR CMAKE_HOST_SOLARIS OR CYGWIN OR MSYS) )
             if (COMPILER_IS_GCC AND CMAKE_CXX_COMPILER_VERSION VERSION_GREATER_EQUAL 8.0)
-                add_compile_options(-fstack-clash-protection -fcf-protection)
+		if (NOT (${CMAKE_SYSTEM_PROCESSOR} MATCHES "arm" OR ${CMAKE_SYSTEM_PROCESSOR} MATCHES "powerpc"))
+			add_compile_options(-fstack-clash-protection -fcf-protection)
+		else()
+			add_compile_options(-fstack-clash-protection)
+		endif()
             endif()
 
             if( (COMPILER_IS_GCC   AND CMAKE_CXX_COMPILER_VERSION VERSION_GREATER_EQUAL 5.0) # Not in GCC 4.8
