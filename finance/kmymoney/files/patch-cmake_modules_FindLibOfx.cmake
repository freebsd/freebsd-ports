Use CMake to find libofx instead of just relying on pkgconf

--- cmake/modules/FindLibOfx.cmake.orig	2018-09-08 21:02:21 UTC
+++ cmake/modules/FindLibOfx.cmake
@@ -5,6 +5,7 @@
 #  LIBOFX_INCLUDE_DIR - the LibOfx include directory
 #  LIBOFX_LIBRARIES - Link these to LibOfx
 #  LIBOFX_DEFINITIONS - Compiler switches required for using LibOfx
+#  LIBOFX_VERSION_STRING - version of LibOfx found (since CMake 2.8.8)
 
 # Copyright (c) 2006, Alexander Neundorf, <neundorf@kde.org>
 # Copied from FindLibXslt.cmake, 2009, Guillaume DE BURE, <gdebure@yahoo.com>
@@ -12,95 +13,66 @@
 # Redistribution and use is allowed according to the terms of the BSD license.
 # For details see the accompanying COPYING-CMAKE-SCRIPTS file.
 
+include(FindPackageHandleStandardArgs)
+
 if(NOT LIBOFX_MIN_VERSION)
   set(LIBOFX_MIN_VERSION "0.9.4")
 endif(NOT LIBOFX_MIN_VERSION)
 
-IF (LIBOFX_INCLUDE_DIR AND LIBOFX_LIBRARIES)
-   # in cache already
-   SET(LIBOFX_FIND_QUIETLY TRUE)
-ENDIF (LIBOFX_INCLUDE_DIR AND LIBOFX_LIBRARIES)
+# use pkg-config to get the directories and then use these values
+# in the find_path() and find_library() calls
+find_package(PkgConfig QUIET)
+pkg_check_modules(PC_LIBOFX QUIET libofx>=${LIBOFX_MIN_VERSION})
+set(LIBOFX_DEFINITIONS ${PC_LIBOFX_CFLAGS_OTHER})
 
-IF (NOT WIN32 AND NOT APPLE)
-   # use pkg-config to get the directories and then use these values
-   # in the FIND_PATH() and FIND_LIBRARY() calls
-   FIND_PACKAGE(PkgConfig)
+find_path(LIBOFX_INCLUDE_DIR
+  NAMES libofx/libofx.h
+  HINTS ${PC_OFX_INCLUDEDIR}
+)
 
-   # according to https://svnweb.freebsd.org/ports/head/finance/kmymoney/files/patch-cmake_modules_FindLibOfx.cmake?view=markup
-   # FreeBSD needs a little different variable name here to setup the LibOFX package infrastructure for us.
-   if (CMAKE_SYSTEM_NAME MATCHES "FreeBSD")
-      PKG_CHECK_MODULES(PC_OFX libofx>=${LIBOFX_MIN_VERSION})
-   else (CMAKE_SYSTEM_NAME MATCHES "FreeBSD")
-      PKG_CHECK_MODULES(LIBOFX libofx>=${LIBOFX_MIN_VERSION})
-   endif (CMAKE_SYSTEM_NAME MATCHES "FreeBSD")
+find_library(LIBOFX_LIBRARIES
+  NAMES ofx libofx
+  HINTS ${PC_OFX_LIBDIR}
+)
 
-  FIND_PATH(LIBOFX_INCLUDE_DIR libofx/libofx.h
-      PATHS
-      ${LIBOFX_INCLUDE_DIRS}
-      ${PC_OFX_INCLUDE_DIRS}
-  )
+if(PC_LIBOFX_VERSION)
+  set(LIBOFX_VERSION_STRING ${PC_LIBOFX_VERSION})
+elseif(LIBOFX_INCLUDE_DIR AND EXISTS "${LIBOFX_INCLUDE_DIR}/libofx/libofx.h")
+  file(STRINGS "${LIBOFX_INCLUDE_DIR}/libofx/libofx.h" libofx_version_str
+       REGEX "^#define[\t ]+LIBOFX_VERSION_RELEASE_STRING[\t ]+\".*\"")
+  string(REGEX REPLACE "^#define[\t ]+LIBOFX_VERSION_RELEASE_STRING[\t ]+\"([^\"]*)\".*" "\\1"
+         LIBOFX_VERSION_STRING "${libofx_version_str}")
+  unset(libofx_version_str)
+endif()
 
-ELSE (NOT WIN32 AND NOT APPLE)
-  FIND_PATH(LIBOFX_INCLUDE_DIR libofx/libofx.h
-      PATHS
-      ${PC_OFX_INCLUDEDIR}
-      ${PC_OFX_INCLUDE_DIRS}
-    )
-
-  FIND_LIBRARY(LIBOFX_LIBRARIES NAMES ofx libofx
-      PATHS
-      ${PC_OFX_LIBDIR}
-      ${PC_OFX_LIBRARY_DIRS}
-    )
-
-  IF (LIBOFX_INCLUDE_DIR AND LIBOFX_LIBRARIES)
-    SET(LIBOFX_FOUND TRUE)
-  ELSE (LIBOFX_INCLUDE_DIR AND LIBOFX_LIBRARIES)
-    SET(LIBOFX_FOUND FALSE)
-  ENDIF (LIBOFX_INCLUDE_DIR AND LIBOFX_LIBRARIES)
-ENDIF (NOT WIN32 AND NOT APPLE)
-
-IF (LIBOFX_FOUND)
-   IF (NOT LIBOFX_FIND_QUIETLY)
-      MESSAGE(STATUS "Found LibOfx: ${LIBOFX_LIBRARY_DIRS}")
-   ENDIF (NOT LIBOFX_FIND_QUIETLY)
-ELSE (LIBOFX_FOUND)
-   IF (LibOfx_FIND_REQUIRED)
-      MESSAGE(FATAL_ERROR "Could NOT find LibOfx")
-   ENDIF (LibOfx_FIND_REQUIRED)
-ENDIF (LIBOFX_FOUND)
-
 # since on Windows for now libofx is a static library we need to add libopensp and libiconv (just like when linking libofx)
-IF (WIN32)
-    SET(OPENSP_FOUND FALSE)
-    FIND_PATH(OPENSP_INCLUDES ParserEventGeneratorKit.h
-        $ENV{KDEROOT}/include/opensp
-    )
+if(WIN32)
+  find_path(OPENSP_INCLUDE_DIR
+    NAMES ParserEventGeneratorKit.h
+    HINTS $ENV{KDEROOT}/include/opensp $ENV{KDEROOT}/include/OpenSP
+  )
 
-    FIND_LIBRARY(OPENSP_LIBRARIES
-        NAMES sp133 libosp
-        PATHS
-            $ENV{KDEROOT}/lib
-    )
+  find_library(OPENSP_LIBRARIES
+    NAMES osp libosp sp133
+    HINTS $ENV{KDEROOT}/lib
+  )
 
-    FIND_LIBRARY(ICONV_LIBRARIES iconv)
+  find_library(ICONV_LIBRARIES iconv)
 
-    IF (OPENSP_INCLUDES AND OPENSP_OPENSP_LIBRARIES)
-        set(OPENSP_FOUND TRUE)
-    ENDIF (OPENSP_INCLUDES AND OPENSP_OPENSP_LIBRARIES)
+  find_package_handle_standard_args(OpenSP
+                                    REQUIRED_VARS OPENSP_LIBRARIES OPENSP_INCLUDE_DIR
+  )
+  find_package_handle_standard_args(iconv
+                                    REQUIRED_VARS ICONV_LIBRARIES
+  )
 
-  IF (OPENSP_FOUND)
-    IF (NOT OPENSP_FIND_QUIETLY)
-      MESSAGE(STATUS "Found OPENSP library: ${OPENSP_LIBRARIES}")
-    ENDIF (NOT OPENSP_FIND_QUIETLY)
+  set(LIBOFX_LIBRARIES ${LIBOFX_LIBRARIES} ${OPENSP_LIBRARIES} ${ICONV_LIBRARIES})
+endif()
 
-  ELSE (OPENSP_FOUND)
-    IF (OPENSP_FIND_REQUIRED)
-      MESSAGE(FATAL_ERROR "Could NOT find OPENSP library\nPlease install it first")
-    ENDIF (OPENSP_FIND_REQUIRED)
-  ENDIF (OPENSP_FOUND)
-  SET(LIBOFX_LIBRARIES ${LIBOFX_LIBRARIES} ${OPENSP_LIBRARIES} ${ICONV_LIBRARIES})
-ENDIF (WIN32)
-
-MARK_AS_ADVANCED(LIBOFX_INCLUDE_DIR  LIBOFX_LIBRARIES )
+find_package_handle_standard_args(LibOFX
+                                  REQUIRED_VARS LIBOFX_LIBRARIES LIBOFX_INCLUDE_DIR
+                                  VERSION_VAR LIBOFX_VERSION_STRING
+)
+                                  
+mark_as_advanced(LIBOFX_INCLUDE_DIR LIBOFX_LIBRARIES)
 
