--- CMakeExternalLibs.cmake.orig	2018-03-16 21:26:02 UTC
+++ CMakeExternalLibs.cmake
@@ -66,7 +66,7 @@ endif()
 # ------------------------------------------------------------------------------
 # OpenMP
 # ------------------------------------------------------------------------------
-find_package(OpenMP QUIET)
+#find_package(OpenMP QUIET) # Broken on FreeBSD: https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=223678
 if (OPENMP_FOUND)
 	message("OpenMP found")
     set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
