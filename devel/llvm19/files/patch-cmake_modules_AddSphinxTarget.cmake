--- llvm/cmake/modules/AddSphinxTarget.cmake.orig
+++ llvm/cmake/modules/AddSphinxTarget.cmake
@@ -39,6 +39,8 @@
   endif()
 
   add_custom_target(${SPHINX_TARGET_NAME}
+                    COMMAND ${CMAKE_COMMAND}
+                            -E make_directory ${SPHINX_BUILD_DIR}
                     COMMAND ${CMAKE_COMMAND} -E env ${ARG_ENV_VARS}
                             ${SPHINX_EXECUTABLE}
                             -b ${builder}
