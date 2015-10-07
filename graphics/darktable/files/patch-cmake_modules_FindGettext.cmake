--- cmake/modules/FindGettext.cmake.orig	2015-07-26 11:47:47 UTC
+++ cmake/modules/FindGettext.cmake
@@ -13,6 +13,8 @@ include(LibFindMacros)
 # On Linux there is no pkgconfig script, but with this we force Gettext_PKGCONF_INCLUDE_DIRS to ""
 if(CMAKE_SYSTEM_NAME STREQUAL "Linux")
   set(Gettext_PKGCONF_INCLUDE_DIRS "")
+elseif(CMAKE_SYSTEM_NAME STREQUAL "FreeBSD")
+  set(Gettext_PKGCONF_INCLUDE_DIRS "/usr/local/include")
 else(CMAKE_SYSTEM_NAME STREQUAL "Linux")
   libfind_pkg_check_modules(Gettext_PKGCONF Gettext)
 endif(CMAKE_SYSTEM_NAME STREQUAL "Linux")
