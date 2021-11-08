--- cmake/find/ldap.cmake.orig	2021-09-13 15:27:47.655692000 +0200
+++ cmake/find/ldap.cmake	2021-09-13 15:28:02.970539000 +0200
@@ -64,6 +64,7 @@ if (NOT OPENLDAP_FOUND AND NOT MISSING_INTERNAL_LDAP_L
         ( "${_system_name}" STREQUAL "linux"   AND "${_system_processor}" STREQUAL "aarch64" ) OR
         ( "${_system_name}" STREQUAL "linux"   AND "${_system_processor}" STREQUAL "ppc64le" ) OR
         ( "${_system_name}" STREQUAL "freebsd" AND "${_system_processor}" STREQUAL "x86_64"  ) OR
+        ( "${_system_name}" STREQUAL "freebsd" AND "${_system_processor}" STREQUAL "aarch64" ) OR
         ( "${_system_name}" STREQUAL "darwin"  AND "${_system_processor}" STREQUAL "x86_64"  ) OR
         ( "${_system_name}" STREQUAL "darwin"  AND "${_system_processor}" STREQUAL "aarch64"   )
     )
