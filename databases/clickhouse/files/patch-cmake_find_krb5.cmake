--- cmake/find/krb5.cmake.orig	2021-12-26 09:29:33 UTC
+++ cmake/find/krb5.cmake
@@ -5,7 +5,7 @@ if (NOT EXISTS "${ClickHouse_SOURCE_DIR}/contrib/krb5/
     set (ENABLE_KRB5 0)
 endif ()
 
-if (NOT CMAKE_SYSTEM_NAME MATCHES "Linux" AND NOT (CMAKE_SYSTEM_NAME MATCHES "Darwin" AND NOT CMAKE_CROSSCOMPILING))
+if (NOT CMAKE_SYSTEM_NAME MATCHES "Linux" AND NOT CMAKE_SYSTEM_NAME MATCHES "FreeBSD" AND NOT (CMAKE_SYSTEM_NAME MATCHES "Darwin" AND NOT CMAKE_CROSSCOMPILING))
     message (WARNING "krb5 disabled in non-Linux and non-native-Darwin environments")
     set (ENABLE_KRB5 0)
 endif ()
