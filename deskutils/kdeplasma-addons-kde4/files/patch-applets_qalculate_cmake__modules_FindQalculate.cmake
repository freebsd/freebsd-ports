Backport several commits from
https://cgit.kde.org/plasma-workspace.git/tree/cmake/FindQalculate.cmake
to make compatible with libqalculate >= 2.0.0. Specifically:
8b3f6ac7a959300803334f6959184a6df34360f0
b915e5b4bab10af938441ac5cae8e62cf6bbb843
2aa504340e68ac11ac68a7b9573354ad431f2995

--- applets/qalculate/cmake_modules/FindQalculate.cmake.orig	2014-10-25 07:17:51 UTC
+++ applets/qalculate/cmake_modules/FindQalculate.cmake
@@ -22,20 +43,48 @@ if(QALCULATE_CFLAGS AND QALCULATE_LIBRARIES)
 
 else(QALCULATE_CFLAGS AND QALCULATE_LIBRARIES)
   if(NOT WIN32)
-    include(UsePkgConfig)
+    find_package(PkgConfig)
 
     if(QALCULATE_MIN_VERSION)
-      exec_program(${PKGCONFIG_EXECUTABLE} ARGS libqalculate --atleast-version=${QALCULATE_MIN_VERSION} RETURN_VALUE _return_VALUE OUTPUT_VARIABLE _pkgconfigDevNull)
+      pkg_check_modules(_pc_QALCULATE libqalculate>=${QALCULATE_MIN_VERSION})
     else(QALCULATE_MIN_VERSION)
-      exec_program(${PKGCONFIG_EXECUTABLE} ARGS libqalculate --exists RETURN_VALUE _return_VALUE OUTPUT_VARIABLE _pkgconfigDevNull)
+      pkg_check_modules(_pc_QALCULATE libqalculate)
     endif(QALCULATE_MIN_VERSION)
 
-    if(_return_VALUE STREQUAL "0")
-      exec_program(${PKGCONFIG_EXECUTABLE} ARGS libqalculate --libs OUTPUT_VARIABLE QALCULATE_LIBRARIES)
-      exec_program(${PKGCONFIG_EXECUTABLE} ARGS cln --libs OUTPUT_VARIABLE CLN_LIBRARIES)
-      exec_program(${PKGCONFIG_EXECUTABLE} ARGS libqalculate --cflags OUTPUT_VARIABLE QALCULATE_CFLAGS)
-      set(QALCULATE_FOUND TRUE)
-    endif(_return_VALUE STREQUAL "0")
+    if(_pc_QALCULATE_FOUND)
+      if(${_pc_QALCULATE_VERSION} VERSION_LESS 2.0.0)
+        pkg_check_modules(_pc_CLN cln)
+      endif()
+      set(QALCULATE_CFLAGS ${_pc_QALCULATE_CFLAGS})
+    endif()
+
+    find_library(QALCULATE_LIBRARIES
+      NAMES
+      qalculate
+      PATHS
+      ${_pc_QALCULATE_LIBRARY_DIRS}
+      ${LIB_INSTALL_DIR}
+    )
+
+    find_path(QALCULATE_INCLUDE_DIR
+      NAMES
+      libqalculate
+      PATHS
+      ${_pc_QALCULATE_INCLUDE_DIRS}
+      ${INCLUDE_INSTALL_DIR}
+    )
+
+    if(_pc_QALCULATE_FOUND)
+      if(${_pc_QALCULATE_VERSION} VERSION_LESS 2.0.0)
+        find_library(CLN_LIBRARIES
+          NAMES
+          cln
+          PATHS
+          ${_pc_CLN_LIBRARY_DIRS}
+          ${LIB_INSTALL_DIR}
+        )
+      endif()
+    endif()
 
   else(NOT WIN32)
     # XXX: currently no libqalculate on windows
