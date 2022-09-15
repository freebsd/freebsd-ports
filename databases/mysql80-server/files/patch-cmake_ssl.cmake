--- cmake/ssl.cmake.orig	2022-07-06 21:36:34 UTC
+++ cmake/ssl.cmake
@@ -142,7 +142,7 @@ MACRO(FIND_OPENSSL_VERSION)
     # Encoded as MNNFFPPS: major minor fix patch status
     FILE(STRINGS "${OPENSSL_INCLUDE_DIR}/openssl/opensslv.h"
       OPENSSL_VERSION_NUMBER
-      REGEX "^#[ ]*define[\t ]+OPENSSL_VERSION_NUMBER[\t ]+0x[0-9].*"
+      REGEX "^#[\t ]*define[\t ]+OPENSSL_VERSION_NUMBER[\t ]+0x[0-9].*"
       )
     STRING(REGEX REPLACE
       "^.*OPENSSL_VERSION_NUMBER[\t ]+0x([0-9]).*$" "\\1"
@@ -380,8 +380,9 @@ MACRO (MYSQL_CHECK_SSL)
         "Not a supported openssl version in WITH_SSL=${WITH_SSL}.")
     ENDIF()
 
-    IF("${OPENSSL_MAJOR_MINOR_FIX_VERSION}" VERSION_GREATER "1.1.0")
-       ADD_DEFINITIONS(-DHAVE_TLSv13)
+    CHECK_SYMBOL_EXISTS(TLS1_3_VERSION "openssl/tls1.h" HAVE_TLS1_3_VERSION)
+    IF(HAVE_TLS1_3_VERSION)
+       #ADD_DEFINITIONS(-DHAVE_TLSv13)
     ENDIF()
 
     IF(OPENSSL_INCLUDE_DIR AND
