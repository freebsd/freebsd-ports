--- ./cmake/platform.cmake.orig	2013-07-19 15:08:25.918110424 +0930
+++ ./cmake/platform.cmake	2013-07-19 15:11:10.254109449 +0930
@@ -32,6 +32,9 @@
     elseif (${CMAKE_SYSTEM_NAME} STREQUAL "FreeBSD")
         set (platform "FreeBSD")
         set (CXXFLAGS "${CXXFLAGS} -DFREEBSD")
+        if (${CMAKE_SYSTEM_PROCESSOR} STREQUAL "i386")
+            set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -march=i586")
+        endif()
     else ()
         string (TOLOWER ${CMAKE_SYSTEM_NAME} platform)
     endif ()
