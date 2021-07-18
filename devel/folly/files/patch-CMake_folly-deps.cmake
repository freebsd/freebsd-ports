--- CMake/folly-deps.cmake.orig	2021-06-27 11:38:58 UTC
+++ CMake/folly-deps.cmake
@@ -175,7 +175,7 @@ find_package(Backtrace)
 set(FOLLY_HAVE_BACKTRACE ${Backtrace_FOUND})
 set(FOLLY_HAVE_DWARF ${LIBDWARF_FOUND})
 if (NOT WIN32 AND NOT APPLE)
-  set(FOLLY_USE_SYMBOLIZER ON)
+  set(FOLLY_USE_SYMBOLIZER ${FREEBSD_FOLLY_USE_SYMBOLIZER})
 endif()
 message(STATUS "Setting FOLLY_USE_SYMBOLIZER: ${FOLLY_USE_SYMBOLIZER}")
 message(STATUS "Setting FOLLY_HAVE_ELF: ${FOLLY_HAVE_ELF}")
