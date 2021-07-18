--- cmake/FindUnwind.cmake.orig	2021-05-28 14:02:50 UTC
+++ cmake/FindUnwind.cmake
@@ -19,7 +19,8 @@ elseif (CMAKE_SYSTEM_PROCESSOR STREQUAL "x86_64" OR
     set (Unwind_ARCH "x86_64")
 elseif (CMAKE_SYSTEM_PROCESSOR MATCHES "^i.86$")
     set (Unwind_ARCH "x86")
-elseif (CMAKE_SYSTEM_PROCESSOR MATCHES "^ppc64")
+elseif (CMAKE_SYSTEM_PROCESSOR MATCHES "^ppc64" OR
+	CMAKE_SYSTEM_PROCESSOR MATCHES "^powerpc64")
     set (Unwind_ARCH "ppc64")
 elseif (CMAKE_SYSTEM_PROCESSOR MATCHES "^ppc")
     set (Unwind_ARCH "ppc32")
