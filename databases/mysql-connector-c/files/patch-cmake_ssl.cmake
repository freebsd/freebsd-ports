--- cmake/ssl.cmake.orig	2015-02-25 21:09:49 UTC
+++ cmake/ssl.cmake
@@ -164,9 +164,9 @@ MACRO (MYSQL_CHECK_SSL)
     # Verify version number. Version information looks like:
     #   #define OPENSSL_VERSION_NUMBER 0x1000103fL
     # Encoded as MNNFFPPS: major minor fix patch status
-    FILE(STRINGS "${OPENSSL_INCLUDE_DIR}/openssl/opensslv.h"
+    FILE(STRINGS "${OPENSSL_INCLUDE_DIR}/opensslv.h"
       OPENSSL_VERSION_NUMBER
-      REGEX "^#define[\t ]+OPENSSL_VERSION_NUMBER[\t ]+0x[0-9].*"
+      REGEX "^#[\t ]define[\t ]+OPENSSL_VERSION_NUMBER[\t ]+0x[0-9].*"
     )
     STRING(REGEX REPLACE
       "^.*OPENSSL_VERSION_NUMBER[\t ]+0x([0-9]).*$" "\\1"
