--- adm/cmake/occt_macros.cmake.orig	2026-11-21 22:23:39 UTC
+++ adm/cmake/occt_macros.cmake
@@ -63,7 +63,7 @@ macro (OCCT_MAKE_OS_WITH_BITNESS)
   elseif(APPLE)
     set (OS_WITH_BIT "mac${COMPILER_BITNESS}")
   else()
-    set (OS_WITH_BIT "lin${COMPILER_BITNESS}")
+    set (OS_WITH_BIT "bsd${COMPILER_BITNESS}")
   endif()
 endmacro()
 
@@ -420,7 +420,7 @@ macro (CONFIGURE_AND_INSTALL_VERSION_HEADER)
     set(BUILD_OCCT_VERSION_EXT "${OCC_VERSION_STRING_EXT}" CACHE STRING "OCCT Version string. Used only for caching, can't impact on build. For modification of version, please check adm/cmake/version.cmake" FORCE)
     mark_as_advanced(BUILD_OCCT_VERSION_EXT)
     string(TIMESTAMP OCCT_VERSION_DATE "%Y-%m-%d" UTC)
-    OCCT_CONFIGURE_AND_INSTALL ("adm/templates/Standard_Version.hxx.in" "${INSTALL_DIR_INCLUDE}/Standard_Version.hxx" "Standard_Version.hxx" "${INSTALL_DIR_INCLUDE}")
+    OCCT_CONFIGURE_AND_INSTALL ("adm/templates/Standard_Version.hxx.in" "${OCCT_BINARY_DIR}/${INSTALL_DIR_INCLUDE}/Standard_Version.hxx" "Standard_Version.hxx" "${INSTALL_DIR_INCLUDE}")
   endif()
 endmacro()
 
