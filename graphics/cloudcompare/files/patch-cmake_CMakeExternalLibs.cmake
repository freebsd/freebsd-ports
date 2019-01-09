--- cmake/CMakeExternalLibs.cmake.orig	2019-01-07 13:42:34.210570000 -0500
+++ cmake/CMakeExternalLibs.cmake	2019-01-07 13:45:18.201885000 -0500
@@ -67,7 +67,7 @@
 # ------------------------------------------------------------------------------
 # OpenMP
 # ------------------------------------------------------------------------------
-find_package(OpenMP QUIET)
+find_package(OpenMP QUIET) # Broken on FreeBSD: https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=223678
 if (OPENMP_FOUND)
 	message("OpenMP found")
     set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
