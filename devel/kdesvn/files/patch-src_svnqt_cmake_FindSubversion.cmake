--- src/svnqt/cmake/FindSubversion.cmake.orig	2016-05-21 09:13:40 UTC
+++ src/svnqt/cmake/FindSubversion.cmake
@@ -109,6 +109,7 @@ if(UNIX)
   check_include_files(execinfo.h HAS_BACKTRACE_H)
   if(HAS_BACKTRACE_H)
     option(USE_BACKTRACE "Generate a backtrace when a svnclient exception is thrown" OFF)
+    set(SUBVERSION_ALL_LIBS ${SUBVERSION_ALL_LIBS} %%EXECINFO%%)
   endif()
 
 endif()

