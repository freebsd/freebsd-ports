--- cmake/FindIconv.cmake.orig	2015-01-25 07:40:23 UTC
+++ cmake/FindIconv.cmake
@@ -33,39 +33,24 @@ if(ICONV_FOUND)
    set(ICONV_FIND_QUIETLY TRUE)
 endif()
 
-include(CheckLibraryExists)
 include(CheckFunctionExists)
 
-find_path(ICONV_INCLUDE_PATH
-  NAMES iconv.h
-  PATHS /usr/include /usr/local/include /usr/pkg/include
-)
-
-find_library(ICONV_LIBRARY
-  NAMES iconv
-  PATHS /lib /usr/lib /usr/local/lib /usr/pkg/lib
-)
+find_path(ICONV_INCLUDE_PATH iconv.h)
 
 if(ICONV_INCLUDE_PATH)
-  if(ICONV_LIBRARY)
-    string(REGEX REPLACE "/[^/]*$" "" ICONV_LIB_PATH "${ICONV_LIBRARY}")
-    check_library_exists(iconv libiconv_open ${ICONV_LIB_PATH} LIBICONV_OPEN_FOUND)
-    check_library_exists(iconv iconv_open ${ICONV_LIB_PATH} ICONV_OPEN_FOUND)
-    if(LIBICONV_OPEN_FOUND OR ICONV_OPEN_FOUND)
-       set(ICONV_FOUND TRUE)
-    endif()
-  else()
-    check_function_exists(iconv_open ICONV_FOUND)
-  endif()
+  check_function_exists(iconv ICONV_FOUND)
+  if(NOT ICONV_FOUND)
+    find_library(ICONV_LIBRARY NAMES iconv libiconv libiconv-2)
+    if(ICONV_LIBRARY)
+      set(ICONV_FOUND TRUE)
+    endif(ICONV_LIBRARY)
+  endif(NOT ICONV_FOUND)
 endif()
 
 include(CheckCSourceCompiles)
 
-if(ICONV_LIBRARY)
-  set(CMAKE_REQUIRED_LIBRARIES ${ICONV_LIBRARY})
-  set(CMAKE_REQUIRED_INCLUDES ${ICONV_INCLUDE_PATH})
-endif()
-
+set(CMAKE_REQUIRED_LIBRARIES ${ICONV_LIBRARY})
+set(CMAKE_REQUIRED_INCLUDES ${ICONV_INCLUDE_PATH})
 set(CMAKE_REQUIRED_FLAGS -Werror)
 check_c_source_compiles("
   #include <iconv.h>
@@ -80,6 +65,10 @@ check_c_source_compiles("
   }
 " ICONV_2ARG_IS_CONST)
 
+set(CMAKE_REQUIRED_LIBRARIES)
+set(CMAKE_REQUIRED_INCLUDES)
+set(CMAKE_REQUIRED_FLAGS)
+
 mark_as_advanced(
   ICONV_INCLUDE_PATH
   ICONV_LIBRARY
