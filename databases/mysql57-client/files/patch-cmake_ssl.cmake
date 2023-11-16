--- cmake/ssl.cmake.orig	2023-10-25 22:22:28.748647000 +0200
+++ cmake/ssl.cmake	2023-10-30 19:12:39.388494000 +0100
@@ -232,13 +232,6 @@ MACRO (MYSQL_CHECK_SSL)
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
@@ -253,9 +246,10 @@ MACRO (MYSQL_CHECK_SSL)
       FIND_OPENSSL_VERSION()
     ENDIF()
 
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
