--- cmake/ssl.cmake.orig	2016-08-24 15:07:34 UTC
+++ cmake/ssl.cmake
@@ -141,11 +141,6 @@ MACRO (MYSQL_CHECK_SSL)
       MESSAGE(STATUS "OPENSSL_APPLINK_C ${OPENSSL_APPLINK_C}")
     ENDIF()
 
-    # On mac this list is <.dylib;.so;.a>
-    # We prefer static libraries, so we revert it here.
-    IF (WITH_SSL_PATH)
-      LIST(REVERSE CMAKE_FIND_LIBRARY_SUFFIXES)
-    ENDIF()
     MESSAGE(STATUS "suffixes <${CMAKE_FIND_LIBRARY_SUFFIXES}>")
     FIND_LIBRARY(OPENSSL_LIBRARIES
                  NAMES ssl ssleay32 ssleay32MD
@@ -153,9 +148,6 @@ MACRO (MYSQL_CHECK_SSL)
     FIND_LIBRARY(CRYPTO_LIBRARY
                  NAMES crypto libeay32
                  HINTS ${OPENSSL_ROOT_DIR}/lib)
-    IF (WITH_SSL_PATH)
-      LIST(REVERSE CMAKE_FIND_LIBRARY_SUFFIXES)
-    ENDIF()
 
     IF(OPENSSL_INCLUDE_DIR AND
        OPENSSL_LIBRARIES   AND
