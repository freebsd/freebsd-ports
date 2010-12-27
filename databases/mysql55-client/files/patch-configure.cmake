--- configure.cmake.orig	2010-12-24 10:05:05.000000000 +0100
+++ configure.cmake	2010-12-24 10:06:21.000000000 +0100
@@ -144,7 +144,6 @@
   IF(NOT LIBRT)
     MY_SEARCH_LIBS(clock_gettime rt LIBRT)
   ENDIF()
-  FIND_PACKAGE(Threads)
 
   SET(CMAKE_REQUIRED_LIBRARIES 
     ${LIBM} ${LIBNSL} ${LIBBIND} ${LIBCRYPT} ${LIBSOCKET} ${LIBDL} ${CMAKE_THREAD_LIBS_INIT} ${LIBRT})
@@ -265,9 +264,6 @@
   CHECK_INCLUDE_FILES (sys/ptem.h HAVE_SYS_PTEM_H)
 ENDIF()
 
-# Figure out threading library
-#
-FIND_PACKAGE (Threads)
 
 #
 # Tests for functions
