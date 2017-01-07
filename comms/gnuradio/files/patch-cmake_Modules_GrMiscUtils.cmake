--- cmake/Modules/GrMiscUtils.cmake.orig	2016-09-02 04:16:12 UTC
+++ cmake/Modules/GrMiscUtils.cmake
@@ -148,7 +148,31 @@ function(GR_LIBRARY_FOO target)
         ARCHIVE DESTINATION ${GR_LIBRARY_DIR} COMPONENT ${GR_LIBRARY_DEVEL_COMPONENT}   # .lib file
         RUNTIME DESTINATION ${GR_RUNTIME_DIR} COMPONENT ${GR_LIBRARY_RUNTIME_COMPONENT} # .dll file
     )
+    
+
+    if(CMAKE_SYSTEM_NAME STREQUAL "FreeBSD")
+        #create .la file
+        GR_LIBTOOL(TARGET ${target} DESTINATION ${GR_LIBRARY_DIR})
+        set_target_properties(${target} PROPERTIES OUTPUT_NAME ${target} SOVERSION ${LIBVER})
+        set(target_name lib${target}.so.${LIBVER})
+
+        #custom command to generate symlinks
+        add_custom_command(
+            TARGET ${target}
+            POST_BUILD
+            COMMAND ${CMAKE_COMMAND} -E create_symlink ${target_name} "${CMAKE_CURRENT_BINARY_DIR}/lib${target}.so"
+            COMMAND ${CMAKE_COMMAND} -E create_symlink ${target_name} "${CMAKE_CURRENT_BINARY_DIR}/lib${target}.so.${MAJOR_VERSION}"
+            COMMAND ${CMAKE_COMMAND} -E touch ${target_name} #so the symlinks point to something valid so cmake 2.6 will install
+        )
 
+        #and install the extra symlinks
+        install(
+            FILES
+            ${CMAKE_CURRENT_BINARY_DIR}/lib${target}.so.${MAJOR_VERSION}
+            ${CMAKE_CURRENT_BINARY_DIR}/lib${target}.so.${LIBVER}
+            DESTINATION ${GR_LIBRARY_DIR} COMPONENT ${GR_LIBRARY_RUNTIME_COMPONENT}
+    )
+    endif()
     #extras mode enabled automatically on linux
     if(NOT DEFINED LIBRARY_EXTRAS)
         set(LIBRARY_EXTRAS ${LINUX})
