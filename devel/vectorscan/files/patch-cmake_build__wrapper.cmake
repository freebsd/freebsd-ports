--- cmake/build_wrapper.cmake.orig	2026-11-11 06:41:19 UTC
+++ cmake/build_wrapper.cmake
@@ -4,6 +4,11 @@ if (WINDOWS)
     add_custom_target(${LIBCSYMS} COMMAND ${CMAKE_COMMAND} -E env "PATH=C:\\msys64\\ucrt64\\bin;C:\\msys64\\usr\\bin;%PATH%"
 	              bash ${CMAKE_MODULE_PATH}/libcsyms.sh ${CMAKE_C_COMPILER} ${LIBC} ${LIBCSYMS} -j
                       WORKING_DIRECTORY ${CMAKE_BINARY_DIR})
+elseif (CMAKE_SYSTEM_NAME STREQUAL "FreeBSD")
+    set(LIBC "/lib/libc.so.7")
+    set(LIBCSYMS libc.so.7.syms)
+    add_custom_target(${LIBCSYMS} COMMAND sh ${CMAKE_MODULE_PATH}/libcsyms.sh ${CMAKE_C_COMPILER} ${LIBC} ${LIBCSYMS} -D
+                      WORKING_DIRECTORY ${CMAKE_BINARY_DIR})
 else()
     set(LIBC "libc.so.6")
     set(LIBCSYMS ${LIBC}.syms)
