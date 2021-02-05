--- cmake/ssl.cmake.orig	2019-12-06 10:41:47 UTC
+++ cmake/ssl.cmake
@@ -150,22 +150,12 @@ MACRO (MYSQL_CHECK_SSL)
       MESSAGE(STATUS "OPENSSL_APPLINK_C ${OPENSSL_APPLINK_C}")
     ENDIF()
 
-    # On mac this list is <.dylib;.so;.a>
-    # We prefer static libraries, so we reverse it here.
-    IF (WITH_SSL_PATH)
-      LIST(REVERSE CMAKE_FIND_LIBRARY_SUFFIXES)
-      MESSAGE(STATUS "suffixes <${CMAKE_FIND_LIBRARY_SUFFIXES}>")
-    ENDIF()
-
     FIND_LIBRARY(OPENSSL_LIBRARY
                  NAMES ssl libssl ssleay32 ssleay32MD
                  HINTS ${OPENSSL_ROOT_DIR}/lib)
     FIND_LIBRARY(CRYPTO_LIBRARY
                  NAMES crypto libcrypto libeay32
                  HINTS ${OPENSSL_ROOT_DIR}/lib)
-    IF (WITH_SSL_PATH)
-      LIST(REVERSE CMAKE_FIND_LIBRARY_SUFFIXES)
-    ENDIF()
 
     IF(OPENSSL_INCLUDE_DIR)
       # Verify version number. Version information looks like:
@@ -193,9 +183,10 @@ MACRO (MYSQL_CHECK_SSL)
       )
     SET(OPENSSL_VERSION ${OPENSSL_VERSION} CACHE INTERNAL "")
 
-    IF("${OPENSSL_VERSION}" VERSION_GREATER "1.1.0")
-       ADD_DEFINITIONS(-DHAVE_TLSv13)
-       SET(HAVE_TLSv13 1)
+    CHECK_SYMBOL_EXISTS(TLS1_3_VERSION "openssl/tls1.h" HAVE_TLS1_3_VERSION)
+    IF(HAVE_TLS1_3_VERSION)
+       #ADD_DEFINITIONS(-DHAVE_TLSv13)
+       #SET(HAVE_TLSv13 1)
        IF(SOLARIS)
          SET(FORCE_SSL_SOLARIS "-Wl,--undefined,address_of_sk_new_null")
        ENDIF()
@@ -203,7 +204,13 @@ MACRO (MYSQL_CHECK_SSL)
     IF(OPENSSL_INCLUDE_DIR AND
        OPENSSL_LIBRARY   AND
        CRYPTO_LIBRARY      AND
-       OPENSSL_MAJOR_VERSION STREQUAL "1"
+       OPENSSL_MAJOR_VERSION VERSION_GREATER_EQUAL "1"
+      )
+      SET(OPENSSL_FOUND TRUE)
+    ELSEIF(OPENSSL_INCLUDE_DIR AND
+       OPENSSL_LIBRARY   AND
+       CRYPTO_LIBRARY      AND
+       OPENSSL_MAJOR_VERSION STREQUAL "2"
       )
       SET(OPENSSL_FOUND TRUE)
     ELSE()
