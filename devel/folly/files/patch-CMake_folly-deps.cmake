--- CMake/folly-deps.cmake.orig	2020-05-29 02:22:17 UTC
+++ CMake/folly-deps.cmake
@@ -155,7 +155,7 @@ endif()
 find_package(Backtrace)
 set(FOLLY_HAVE_BACKTRACE ${Backtrace_FOUND})
 if (FOLLY_HAVE_ELF_H AND FOLLY_HAVE_BACKTRACE AND LIBDWARF_FOUND)
-  set(FOLLY_USE_SYMBOLIZER ON)
+  set(FOLLY_USE_SYMBOLIZER ${FREEBSD_FOLLY_USE_SYMBOLIZER})
 endif()
 message(STATUS "Setting FOLLY_USE_SYMBOLIZER: ${FOLLY_USE_SYMBOLIZER}")
 
