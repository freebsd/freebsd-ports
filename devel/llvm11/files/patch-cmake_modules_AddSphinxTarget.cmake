--- cmake/modules/AddSphinxTarget.cmake.orig
+++ cmake/modules/AddSphinxTarget.cmake
@@ -29,6 +29,8 @@
   endif()
 
   add_custom_target(${SPHINX_TARGET_NAME}
+		    COMMAND ${CMAKE_COMMAND}
+                            -E make_directory ${SPHINX_BUILD_DIR}
                     COMMAND ${SPHINX_EXECUTABLE}
                             -b ${builder}
                             -d "${SPHINX_DOC_TREE_DIR}"
