--- cmake/WlFunctions.cmake.orig	2022-10-22 11:51:16 UTC
+++ cmake/WlFunctions.cmake
@@ -93,8 +93,8 @@ macro(_common_compile_tasks)
 
   if(ARG_USES_MINIZIP)
       if(MINIZIP_STATIC_LIBRARIES)
-          target_link_libraries(${NAME} minizip)
-          message(STATUS "Link ${NAME} with minizip")
+          target_link_libraries(${NAME} ${MINIZIP_STATIC_LIBRARIES})
+          message(STATUS "Link ${NAME} with ${MINIZIP_STATIC_LIBRARIES}")
       else()
           target_link_libraries(${NAME} third_party_minizip)
           message(STATUS "Link ${NAME} with third_party_minizip")
@@ -103,7 +103,6 @@ macro(_common_compile_tasks)
 
   if(ARG_USES_ATOMIC AND NOT APPLE AND ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang"))
     # clang on linux needs explicit linkage against standard library atomic
-    target_link_libraries(${NAME} atomic)
   endif()
 
   if(ARG_USES_ZLIB)
