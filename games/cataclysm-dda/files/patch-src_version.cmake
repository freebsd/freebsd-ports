--- src/version.cmake.orig	2026-06-19 22:33:11 UTC
+++ src/version.cmake
@@ -21,8 +21,16 @@ if("${GIT_VERSION}" MATCHES "GIT-NOTFOUND")
 message(NOTICE ${GIT_VERSION})
 
 if("${GIT_VERSION}" MATCHES "GIT-NOTFOUND")
+    set(GIT_VERSION "%%DISTVERSION%%")
+    file(WRITE ${CMAKE_SOURCE_DIR}/src/version.h
+            "// NOLINT(cata-header-guard)\n\#define VERSION \"${GIT_VERSION}\"\n")
+    file(WRITE ${CMAKE_SOURCE_DIR}/VERSION.txt "\
+build type: Release\n\
+build number: %%DISTVERSION%%\n\
+commit sha: FreeBSD-Ports\n\
+commit url: https://ports.freebsd.org\n")
     return()
-endif()
+endif() 
 
 if(GIT_VERSION)
     string(REPLACE "-NOTFOUND" "" GIT_VERSION ${GIT_VERSION})
