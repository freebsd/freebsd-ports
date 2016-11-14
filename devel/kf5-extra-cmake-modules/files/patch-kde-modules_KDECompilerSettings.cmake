Make sure we only pass -std=c++0x if the compiler supports it (i.e. it is not base GCC).

--- kde-modules/KDECompilerSettings.cmake.orig	2016-09-15 12:44:43 UTC
+++ kde-modules/KDECompilerSettings.cmake
@@ -194,7 +194,8 @@ if (CMAKE_C_COMPILER_ID STREQUAL "GNU" O
     # compilers (in particular, MSVC 2010 does not support C99)
     set(CMAKE_C_FLAGS   "${CMAKE_C_FLAGS} -std=iso9899:1990")
 endif()
-if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU" OR CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
+if ((CMAKE_COMPILER_IS_GNUCXX AND CMAKE_CXX_COMPILER_VERSION VERSION_GREATER "4.2.4") OR
+    CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
     set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
 elseif (CMAKE_CXX_COMPILER_ID STREQUAL "Intel" AND NOT WIN32)
     set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
