--- cmake/ssl.cmake.orig	2023-03-16 22:25:04.000000000 +0700
+++ cmake/ssl.cmake	2023-06-13 12:11:25.125506000 +0700
@@ -176,24 +176,32 @@ MACRO (MYSQL_CHECK_SSL)
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
-
     IF(OPENSSL_INCLUDE_DIR)
+     FOREACH(version_part
+        OPENSSL_VERSION_MAJOR
+        OPENSSL_VERSION_MINOR
+        OPENSSL_VERSION_PATCH
+     )
+        FILE(STRINGS "${OPENSSL_INCLUDE_DIR}/openssl/opensslv.h" ${version_part}
+        REGEX "^#[\t ]*define[\t ]+${version_part}[\t ]+([0-9]+).*")
+        STRING(REGEX REPLACE
+          "^.*${version_part}[\t ]+([0-9]+).*" "\\1"
+          ${version_part} "${${version_part}}")
+     ENDFOREACH()
+
+     IF(OPENSSL_VERSION_MAJOR VERSION_EQUAL 3)
+      # OpenSSL 3
+        SET(OPENSSL_MAJOR_VERSION "${OPENSSL_VERSION_MAJOR}")
+        SET(OPENSSL_MINOR_VERSION "${OPENSSL_VERSION_MINOR}")
+        SET(OPENSSL_FIX_VERSION "${OPENSSL_VERSION_PATCH}")
+        SET(OPENSSL_FOUND TRUE)
+     ELSE()
       # Verify version number. Version information looks like:
       #   #define OPENSSL_VERSION_NUMBER 0x1000103fL
       # Encoded as MNNFFPPS: major minor fix patch status
@@ -213,15 +221,17 @@ MACRO (MYSQL_CHECK_SSL)
         "^.*OPENSSL_VERSION_NUMBER[\t ]+0x[0-9][0-9][0-9]([0-9][0-9]).*$" "\\1"
         OPENSSL_FIX_VERSION "${OPENSSL_VERSION_NUMBER}"
         )
+     ENDIF()
     ENDIF()
     SET(OPENSSL_VERSION
       "${OPENSSL_MAJOR_VERSION}.${OPENSSL_MINOR_VERSION}.${OPENSSL_FIX_VERSION}"
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
@@ -229,7 +239,13 @@ MACRO (MYSQL_CHECK_SSL)
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
