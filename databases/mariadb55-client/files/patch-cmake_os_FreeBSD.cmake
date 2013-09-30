--- cmake/os/FreeBSD.cmake.orig	2013-09-27 00:09:44.000000000 +0300
+++ cmake/os/FreeBSD.cmake	2013-09-27 00:09:57.000000000 +0300
@@ -24,9 +24,10 @@
 # ADD_DEFINITIONS(-DHAVE_BROKEN_REALPATH)
 
 # Find libexecinfo (library that contains backtrace_symbols etc)
-INCLUDE_DIRECTORIES(/usr/local/include)
-SET(CMAKE_REQUIRED_INCLUDES ${CMAKE_REQUIRED_INCLUDES} /usr/local/include )
-SET(ENV{LIB} "$ENV{LIB}:/usr/local/lib")
+SET(EXECINFO_ROOT /usr/local CACHE INTERNAL "Where to find execinfo library and header")
+INCLUDE_DIRECTORIES(${EXECINFO_ROOT}/include)
+SET(CMAKE_REQUIRED_INCLUDES ${CMAKE_REQUIRED_INCLUDES} ${EXECINFO_ROOT}/include)
+SET(ENV{LIB} "$ENV{LIB}:${EXECINFO_ROOT}/lib")
 FIND_LIBRARY(EXECINFO NAMES execinfo)
 IF(EXECINFO)
  SET(LIBEXECINFO ${EXECINFO})
