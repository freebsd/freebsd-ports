--- cmake/modules/SetUpFreeBSD.cmake.orig	2024-03-21 09:58:40 UTC
+++ cmake/modules/SetUpFreeBSD.cmake
@@ -11,6 +11,9 @@ elseif(CMAKE_SYSTEM_PROCESSOR MATCHES i686)
 elseif(CMAKE_SYSTEM_PROCESSOR MATCHES i686)
   set(FP_MATH_FLAGS "-msse2 -mfpmath=sse")
   set(ROOT_ARCHITECTURE freebsdi686)
+elseif(CMAKE_SYSTEM_PROCESSOR MATCHES i386) # FreeBSD port maintainer note: Treating i386 as i686 might just work...
+  set(FP_MATH_FLAGS "-msse2 -mfpmath=sse")
+  set(ROOT_ARCHITECTURE freebsdi386)
 elseif(CMAKE_SYSTEM_PROCESSOR MATCHES aarch64)
   set(ROOT_ARCHITECTURE freebsdarm64)
 elseif(CMAKE_SYSTEM_PROCESSOR MATCHES arm)
