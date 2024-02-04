--- cmake/re-config.cmake.orig	2024-01-31 07:29:02 UTC
+++ cmake/re-config.cmake
@@ -56,7 +56,6 @@ if(HAVE_RESOLV)
   check_symbol_exists(res_ninit resolv.h HAVE_RESOLV)
 endif()
 if(HAVE_RESOLV)
-  set(RESOLV_LIBRARY resolv)
   list(APPEND RE_DEFINITIONS HAVE_RESOLV)
 else()
   set(RESOLV_LIBRARY)
