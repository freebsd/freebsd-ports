--- adm/cmake/occt_macros.cmake.orig	2018-05-25 19:13:23 UTC
+++ adm/cmake/occt_macros.cmake
@@ -53,7 +53,7 @@ macro (OCCT_MAKE_OS_WITH_BITNESS)
   elseif(APPLE)
     set (OS_WITH_BIT "mac${COMPILER_BITNESS}")
   else()
-    set (OS_WITH_BIT "lin${COMPILER_BITNESS}")
+    set (OS_WITH_BIT "bsd${COMPILER_BITNESS}")
   endif()
 endmacro()
 
@@ -337,7 +337,7 @@ macro (COLLECT_AND_INSTALL_OCCT_HEADER_F
     configure_file ("${TEMPLATE_HEADER_PATH}" "${ROOT_TARGET_OCCT_DIR}/${OCCT_INSTALL_DIR_PREFIX}/${HEADER_FILE_NAME}" @ONLY)
   endforeach()
   
-  install (FILES ${OCCT_HEADER_FILES_COMPLETE} DESTINATION "${INSTALL_DIR}/${OCCT_INSTALL_DIR_PREFIX}")
+  install (FILES ${OCCT_HEADER_FILES_COMPLETE} DESTINATION "${INSTALL_DIR_INCLUDE}")
   
   string(TIMESTAMP CURRENT_TIME "%H:%M:%S")
   message (STATUS "Info: \(${CURRENT_TIME}\) Checking headers in inc folder...")
