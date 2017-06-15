--- cmake/ssl.cmake.orig	2017-03-04 21:14:36 UTC
+++ cmake/ssl.cmake
@@ -166,7 +166,7 @@ MACRO (MYSQL_CHECK_SSL)
     # Encoded as MNNFFPPS: major minor fix patch status
     FILE(STRINGS "${OPENSSL_INCLUDE_DIR}/openssl/opensslv.h"
       OPENSSL_VERSION_NUMBER
-      REGEX "^#[ ]*define[\t ]+OPENSSL_VERSION_NUMBER[\t ]+0x[0-9].*"
+      REGEX "define[\t ]+OPENSSL_VERSION_NUMBER[\t ]+0x[0-9].*"
     )
     STRING(REGEX REPLACE
       "^.*OPENSSL_VERSION_NUMBER[\t ]+0x([0-9]).*$" "\\1"
@@ -176,7 +176,8 @@ MACRO (MYSQL_CHECK_SSL)
     IF(OPENSSL_INCLUDE_DIR AND
        OPENSSL_LIBRARY   AND
        CRYPTO_LIBRARY      AND
-       OPENSSL_MAJOR_VERSION STREQUAL "1"
+       (OPENSSL_MAJOR_VERSION STREQUAL "1" OR
+       OPENSSL_MAJOR_VERSION STREQUAL "2")
       )
       SET(OPENSSL_FOUND TRUE)
     ELSE()
