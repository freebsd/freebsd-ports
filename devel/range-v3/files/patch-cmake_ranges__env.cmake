--- cmake/ranges_env.cmake.orig	2022-11-07 17:22:22 UTC
+++ cmake/ranges_env.cmake
@@ -46,6 +46,11 @@ elseif(CMAKE_SYSTEM_NAME MATCHES "Windows")
   if (RANGES_VERBOSE_BUILD)
     message(STATUS "[range-v3]: system is Windows.")
   endif()
+elseif(CMAKE_SYSTEM_NAME MATCHES "FreeBSD")
+  set (RANGES_ENV_FREEBSD TRUE)
+  if (RANGES_VERBOSE_BUILD)
+    message(STATUS "[range-v3]: system is FreeBSD.")
+  endif()
 elseif(CMAKE_SYSTEM_NAME MATCHES "OpenBSD")
   set (RANGES_ENV_OPENBSD TRUE)
   if (RANGES_VERBOSE_BUILD)
