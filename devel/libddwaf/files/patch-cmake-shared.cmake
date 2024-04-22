--- cmake/shared.cmake.orig	2024-02-07 14:23:49 UTC
+++ cmake/shared.cmake
@@ -1,8 +1,9 @@
-execute_process(COMMAND git rev-parse HEAD
-    WORKING_DIRECTORY ${libddwaf_SOURCE_DIR}
-    OUTPUT_VARIABLE BUILD_ID
-    OUTPUT_STRIP_TRAILING_WHITESPACE
-)
+#execute_process(COMMAND git rev-parse HEAD
+#    WORKING_DIRECTORY ${libddwaf_SOURCE_DIR}
+#    OUTPUT_VARIABLE BUILD_ID
+#    OUTPUT_STRIP_TRAILING_WHITESPACE
+#)
+set(BUILD_ID "044f67522ec5df679fed4786d0ae965170bd63c1")
 
 message(STATUS "Build id is ${BUILD_ID}")
 string(SUBSTRING "${BUILD_ID}" 0 2 BUILD_ID_PREFIX)
@@ -34,9 +35,9 @@ if(LINUX)
             COMMAND ${CMAKE_STRIP} --only-keep-debug ${SYMBOL_FILE}
             COMMAND ${CMAKE_STRIP} $<TARGET_FILE:libddwaf_shared>)
 
-        install(FILES ${SYMBOL_FILE}
-            DESTINATION ${CMAKE_INSTALL_LIBDIR}/.build-id/${BUILD_ID_PREFIX}
-            RENAME ${BUILD_ID_SUFFIX}.debug)
+        #install(FILES ${SYMBOL_FILE}
+        #    DESTINATION ${CMAKE_INSTALL_LIBDIR}/.build-id/${BUILD_ID_PREFIX}
+        #    RENAME ${BUILD_ID_SUFFIX}.debug)
     endif()
 elseif (APPLE)
     target_link_libraries(libddwaf_shared PRIVATE -Wl,-undefined,error libddwaf_shared_objects)
