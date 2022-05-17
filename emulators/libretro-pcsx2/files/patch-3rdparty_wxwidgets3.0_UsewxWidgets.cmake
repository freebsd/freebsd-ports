--- 3rdparty/wxwidgets3.0/UsewxWidgets.cmake.orig	2020-10-29 23:31:05 UTC
+++ 3rdparty/wxwidgets3.0/UsewxWidgets.cmake
@@ -11,7 +11,7 @@ if(UNIX)
    if(APPLE)
       add_definitions(-D__DARWIN__)
    else()
-       add_definitions(-D__LINUX__)
+       add_definitions(-D__BSD__)
    endif()
 elseif(WIN32)
    add_definitions(-D__WINDOWS__)
