--- cmake/ssl.cmake.orig	2021-01-05 17:19:59.000000000 +0700
+++ cmake/ssl.cmake	2023-06-13 13:07:00.168639000 +0700
@@ -169,6 +169,25 @@ MACRO (MYSQL_CHECK_SSL)
     ENDIF()
 
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
@@ -188,14 +207,22 @@ MACRO (MYSQL_CHECK_SSL)
         "^.*OPENSSL_VERSION_NUMBER[\t ]+0x[0-9][0-9][0-9]([0-9][0-9]).*$" "\\1"
         OPENSSL_FIX_VERSION "${OPENSSL_VERSION_NUMBER}"
         )
+     ENDIF()
     ENDIF()
-    IF("${OPENSSL_MAJOR_VERSION}.${OPENSSL_MINOR_VERSION}.${OPENSSL_FIX_VERSION}" VERSION_GREATER "1.1.0")
-       ADD_DEFINITIONS(-DHAVE_TLSv13)
+    CHECK_SYMBOL_EXISTS(TLS1_3_VERSION "openssl/tls1.h" HAVE_TLS1_3_VERSION)
+    IF(HAVE_TLS1_3_VERSION)
+       #ADD_DEFINITIONS(-DHAVE_TLSv13)
     ENDIF()
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
