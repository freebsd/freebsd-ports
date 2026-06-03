--- thirdparty/luajit-cmake/LuaJIT.cmake.orig	2024-10-06 12:32:05 UTC
+++ thirdparty/luajit-cmake/LuaJIT.cmake
@@ -409,7 +409,7 @@ if (CMAKE_HOST_SYSTEM_NAME STREQUAL "Windows")
 endif()
 
 add_custom_command(OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/luajit_relver.txt
-  COMMAND git show -s --format=${GIT_FORMAT} > ${CMAKE_CURRENT_BINARY_DIR}/luajit_relver.txt
+  COMMAND cat .relver > ${CMAKE_CURRENT_BINARY_DIR}/luajit_relver.txt
   WORKING_DIRECTORY ${LUAJIT_DIR}
 )
 
