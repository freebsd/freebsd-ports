--- cmake/Dependencies.cmake.orig	2026-06-19 16:11:53 UTC
+++ cmake/Dependencies.cmake
@@ -19,7 +19,7 @@ if (USE_DBUS)
     find_package(PkgConfig REQUIRED)
     pkg_check_modules(DBUS REQUIRED dbus-1)
     target_include_directories(${PROJECT_NAME} PRIVATE ${DBUS_INCLUDE_DIRS})
-    target_link_libraries(${PROJECT_NAME} PRIVATE ${DBUS_LIBRARIES})
+    target_link_libraries(${PROJECT_NAME} PRIVATE ${DBUS_LINK_LIBRARIES})
 endif ()
 
 if (USE_IPC_SOCKET)
@@ -771,7 +771,8 @@ elseif(CMAKE_SYSTEM_NAME STREQUAL "FreeBSD")
 elseif(CMAKE_SYSTEM_NAME STREQUAL "FreeBSD")
     find_library(UTIL_LIBRARY util REQUIRED)
     # REQUIRED will make sure the build fails earlier if libutil isn't found
-    target_link_libraries(${PROJECT_NAME} PRIVATE ${UTIL_LIBRARY} iconv)
+    find_library(ICONV_LIB iconv PATHS /usr/local/lib REQUIRED)
+    target_link_libraries(${PROJECT_NAME} PRIVATE ${UTIL_LIBRARY} ${ICONV_LIB})
 elseif(CMAKE_SYSTEM_NAME STREQUAL "Haiku")
     target_link_libraries(${PROJECT_NAME} PRIVATE network iconv bsd)
 endif()
