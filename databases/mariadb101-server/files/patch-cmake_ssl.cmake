MariaDB prefers static libraries, breaks builds with
ports' OpenSSL libs

--- cmake/ssl.cmake.orig	2015-12-23 15:33:29 UTC
+++ cmake/ssl.cmake
@@ -145,9 +145,9 @@ MACRO (MYSQL_CHECK_SSL)
 
     # On mac this list is <.dylib;.so;.a>
     # We prefer static libraries, so we revert it here.
-    IF (WITH_SSL_PATH)
-      LIST(REVERSE CMAKE_FIND_LIBRARY_SUFFIXES)
-    ENDIF()
+#    IF (WITH_SSL_PATH)
+#      LIST(REVERSE CMAKE_FIND_LIBRARY_SUFFIXES)
+#    ENDIF()
     FIND_LIBRARY(OPENSSL_LIBRARIES
                  NAMES ssl ssleay32 ssleay32MD
                  HINTS ${OPENSSL_ROOT_DIR}/lib)
