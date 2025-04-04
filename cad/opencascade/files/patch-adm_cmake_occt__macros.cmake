--- adm/cmake/occt_macros.cmake.orig	2025-02-17 22:00:23 UTC
+++ adm/cmake/occt_macros.cmake
@@ -68,7 +68,7 @@ macro (OCCT_MAKE_OS_WITH_BITNESS)
   elseif(APPLE)
     set (OS_WITH_BIT "mac${COMPILER_BITNESS}")
   else()
-    set (OS_WITH_BIT "lin${COMPILER_BITNESS}")
+    set (OS_WITH_BIT "bsd${COMPILER_BITNESS}")
   endif()
 endmacro()
 
@@ -478,7 +478,7 @@ function (COLLECT_AND_INSTALL_OCCT_HEADER_FILES THE_RO
 
   set (OCCT_HEADER_FILES_INSTALLATION ${OCCT_HEADER_FILES_COMPLETE})
   list (FILTER OCCT_HEADER_FILES_INSTALLATION INCLUDE REGEX ".*[.](h|lxx)")
-  install (FILES ${OCCT_HEADER_FILES_INSTALLATION} DESTINATION "${INSTALL_DIR}/${THE_OCCT_INSTALL_DIR_PREFIX}")
+  install (FILES ${OCCT_HEADER_FILES_INSTALLATION} DESTINATION "${THE_OCCT_INSTALL_DIR_PREFIX}")
 endfunction()
 
 # Macro to configure and install Standard_Version.hxx file
@@ -489,7 +489,7 @@ macro (CONFIGURE_AND_INSTALL_VERSION_HEADER)
     set(BUILD_OCCT_VERSION_EXT "${OCC_VERSION_STRING_EXT}" CACHE STRING "OCCT Version string. Used only for caching, can't impact on build. For modification of version, please check adm/cmake/version.cmake" FORCE)
     mark_as_advanced(BUILD_OCCT_VERSION_EXT)
     string(TIMESTAMP OCCT_VERSION_DATE "%Y-%m-%d" UTC)
-    OCCT_CONFIGURE_AND_INSTALL ("adm/templates/Standard_Version.hxx.in" "${INSTALL_DIR_INCLUDE}/Standard_Version.hxx" "Standard_Version.hxx" "${INSTALL_DIR}/${INSTALL_DIR_INCLUDE}")
+    OCCT_CONFIGURE_AND_INSTALL ("adm/templates/Standard_Version.hxx.in" "${OCCT_BINARY_DIR}/${INSTALL_DIR_INCLUDE}/Standard_Version.hxx" "Standard_Version.hxx" "${INSTALL_DIR_INCLUDE}")
   endif()
 endmacro()
 
@@ -762,12 +762,12 @@ macro (OCCT_UPDATE_TARGET_FILE)
 
   install (CODE
   "string (TOLOWER \"\${CMAKE_INSTALL_CONFIG_NAME}\" CMAKE_INSTALL_CONFIG_NAME_LOWERCASE)
-  file (GLOB ALL_OCCT_TARGET_FILES \"${INSTALL_DIR}/${INSTALL_DIR_CMAKE}/OpenCASCADE*Targets-\${CMAKE_INSTALL_CONFIG_NAME_LOWERCASE}.cmake\")
+  file (GLOB ALL_OCCT_TARGET_FILES \"$ENV{DESTDIR}/${INSTALL_DIR_CMAKE}/OpenCASCADE*Targets-\${CMAKE_INSTALL_CONFIG_NAME_LOWERCASE}.cmake\")
   foreach(TARGET_FILENAME \${ALL_OCCT_TARGET_FILES})
     file (STRINGS \"\${TARGET_FILENAME}\" TARGET_FILE_CONTENT)
     file (REMOVE \"\${TARGET_FILENAME}\")
     foreach (line IN LISTS TARGET_FILE_CONTENT)
-      string (REGEX REPLACE \"[\\\\]?[\\\$]{OCCT_INSTALL_BIN_LETTER}\" \"\${OCCT_INSTALL_BIN_LETTER}\" line \"\${line}\")
+      string (REGEX REPLACE \"[\\\\]?[\\\$]{OCCT_INSTALL_BIN_LETTER}\" \"${OCCT_INSTALL_BIN_LETTER}\" line \"\${line}\")
       file (APPEND \"\${TARGET_FILENAME}\" \"\${line}\\n\")
     endforeach()
   endforeach()")
