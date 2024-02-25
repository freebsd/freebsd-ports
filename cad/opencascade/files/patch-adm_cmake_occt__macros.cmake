--- adm/cmake/occt_macros.cmake.orig	2023-12-04 15:53:08 UTC
+++ adm/cmake/occt_macros.cmake
@@ -47,7 +47,7 @@ macro (OCCT_MAKE_OS_WITH_BITNESS)
   elseif(APPLE)
     set (OS_WITH_BIT "mac${COMPILER_BITNESS}")
   else()
-    set (OS_WITH_BIT "lin${COMPILER_BITNESS}")
+    set (OS_WITH_BIT "bsd${COMPILER_BITNESS}")
   endif()
 endmacro()
 
@@ -338,7 +338,7 @@ macro (COLLECT_AND_INSTALL_OCCT_HEADER_FILES ROOT_TARG
     configure_file ("${TEMPLATE_HEADER_PATH}" "${ROOT_TARGET_OCCT_DIR}/${OCCT_INSTALL_DIR_PREFIX}/${HEADER_FILE_NAME}" @ONLY)
   endforeach()
   
-  install (FILES ${OCCT_HEADER_FILES_COMPLETE} DESTINATION "${INSTALL_DIR}/${OCCT_INSTALL_DIR_PREFIX}")
+  install (FILES ${OCCT_HEADER_FILES_COMPLETE} DESTINATION "${INSTALL_DIR_INCLUDE}")
   
   string(TIMESTAMP CURRENT_TIME "%H:%M:%S")
   message (STATUS "Info: \(${CURRENT_TIME}\) Checking headers in inc folder...")
@@ -592,12 +592,12 @@ macro (OCCT_UPDATE_TARGET_FILE)
 
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
