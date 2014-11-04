--- storage/tokudb/ft-index/cmake_modules/TokuFeatureDetection.cmake.orig	2014-09-24 22:29:47 UTC
+++ storage/tokudb/ft-index/cmake_modules/TokuFeatureDetection.cmake
@@ -87,13 +87,7 @@ if (NOT HAVE_DLSYM_WITHOUT_DL)
 endif ()
 check_function_exists(backtrace HAVE_BACKTRACE_WITHOUT_EXECINFO)
 if (NOT HAVE_BACKTRACE_WITHOUT_EXECINFO)
-  set(CMAKE_REQUIRED_LIBRARIES execinfo)
-  check_function_exists(backtrace HAVE_BACKTRACE_WITH_EXECINFO)
-  if (HAVE_BACKTRACE_WITH_EXECINFO)
-    list(APPEND EXTRA_SYSTEM_LIBS execinfo)
-  else ()
-    message(FATAL_ERROR "Cannot find backtrace(), even with -lexecinfo.")
-  endif ()
+  list(APPEND EXTRA_SYSTEM_LIBS execinfo)
 endif ()
 
 if(HAVE_CLOCK_REALTIME)
