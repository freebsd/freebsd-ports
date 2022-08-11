--- 3rdparty/wxwidgets3.0/UsewxWidgets.cmake.orig	2020-10-29 23:31:05 UTC
+++ 3rdparty/wxwidgets3.0/UsewxWidgets.cmake
@@ -5,13 +5,13 @@ set(wxWidgets_LIBRARIES wxwidgets)
 set(wxWidgets_CXX_FLAGS)
 
 include_directories(SYSTEM ${wxWidgets_INCLUDE_DIRS})
-add_definitions(-DwxUSE_GUI=0 -D_FILE_OFFSET_BITS=64)
+add_definitions(-DwxUSE_GUI=0 -D_FILE_OFFSET_BITS=64 -DwxSIZE_T_IS_UINT)
 if(UNIX)
    add_definitions(-DwxUSE_UNIX -D__UNIX__)
    if(APPLE)
       add_definitions(-D__DARWIN__)
    else()
-       add_definitions(-D__LINUX__)
+       add_definitions(-D__BSD__)
    endif()
 elseif(WIN32)
    add_definitions(-D__WINDOWS__)
