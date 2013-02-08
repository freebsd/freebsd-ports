--- cmake/os/FreeBSD.cmake.orig	2013-01-13 02:13:17.000000000 +0200
+++ cmake/os/FreeBSD.cmake	2013-01-13 02:14:15.000000000 +0200
@@ -24,6 +24,7 @@
 # ADD_DEFINITIONS(-DHAVE_BROKEN_REALPATH)
 
 # Find libexecinfo (library that contains backtrace_symbols etc)
+IF(FALSE)
 INCLUDE_DIRECTORIES(/usr/local/include)
 SET(CMAKE_REQUIRED_INCLUDES ${CMAKE_REQUIRED_INCLUDES} /usr/local/include )
 SET(ENV{LIB} "$ENV{LIB}:/usr/local/lib")
@@ -31,6 +32,7 @@
 IF(EXECINFO)
  SET(LIBEXECINFO ${EXECINFO})
 ENDIF()
+ENDIF()
