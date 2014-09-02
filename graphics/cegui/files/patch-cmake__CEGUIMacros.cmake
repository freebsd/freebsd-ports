These two commits are required for the port to build with CMake 3.0.
See patch-CMakeLists.txt as well.

# HG changeset patch
# User Danduk82 <danduk82@hotmail.com>
# Date 1390065964 -3600
# Branch v0-8
# Node ID 320ecd58eb1b3d673eee62a913041f643c50d483
# Parent  83954df05b3b1b94ada2137ef5d028de54d11818
A) fixed new CMAKE policy CMP0045 issue in CMakeLists.txt. This feature was introduced recently in this commit: https://gitorious.org/cmake/cmake/commit/73e93400e2efab2096618ff58a5ad68236cd04aa ... Bb) fixed CMAKE problem with cmake/CEGUIMacros.cmake when including the project with ExternalProject_Add() CMAKE feature in a project. I had to escape the '[' and ']' characters because in this way CMAKE was not recognizing those characters. CMAKE version: 2.8.12.

# HG changeset patch
# User Paul Turner <paul@cegui.org.uk>
# Date 1402736843 -3600
# Branch v0-8
# Node ID 72b84028e58fc307cb2c9749d5cd17fc71059e6a
# Parent  243fc257b6c94452c13cceb65452a665509669dc
FIX: switch to 'if test' syntax from 'if [' for shell commands (cmake issues)
--- ./cmake/CEGUIMacros.cmake.orig	2014-08-29 00:28:26.000000000 +0300
+++ ./cmake/CEGUIMacros.cmake	2014-08-29 00:28:30.000000000 +0300
@@ -309,33 +309,33 @@
     endif()
 
     add_custom_command(TARGET ${_TARGET_NAME} POST_BUILD 
-        COMMAND if [ x${_CEGUI_BUILD_CONFIG} == xDebug ]\; then ce_ext=\"${CEGUI_BUILD_SUFFIX}\"\; else ce_ext=\"\"\; fi\; rm -rf \"${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${_TARGET_NAME}$$ce_ext.app/Contents/Frameworks\"
+        COMMAND if test x${_CEGUI_BUILD_CONFIG} == xDebug \; then ce_ext=\"${CEGUI_BUILD_SUFFIX}\"\; else ce_ext=\"\"\; fi\; rm -rf \"${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${_TARGET_NAME}$$ce_ext.app/Contents/Frameworks\"
         COMMENT "Removing old Frameworks in ${_TARGET_NAME}.app")
     add_custom_command(TARGET ${_TARGET_NAME} POST_BUILD 
-        COMMAND if [ x${_CEGUI_BUILD_CONFIG} == xDebug ]\; then ce_ext=\"${CEGUI_BUILD_SUFFIX}\"\; else ce_ext=\"\"\; fi\; rm -rf \"${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${_TARGET_NAME}$$ce_ext.app/Contents/Resources\"
+        COMMAND if test x${_CEGUI_BUILD_CONFIG} == xDebug \; then ce_ext=\"${CEGUI_BUILD_SUFFIX}\"\; else ce_ext=\"\"\; fi\; rm -rf \"${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${_TARGET_NAME}$$ce_ext.app/Contents/Resources\"
         COMMENT "Removing old Resources in ${_TARGET_NAME}.app")
 
     add_custom_command(TARGET ${_TARGET_NAME} POST_BUILD 
-        COMMAND if [ x${_CEGUI_BUILD_CONFIG} == xDebug ]\; then ce_ext=\"${CEGUI_BUILD_SUFFIX}\"\; else ce_ext=\"\"\; fi\; mkdir -p \"${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${_TARGET_NAME}$$ce_ext.app/Contents/Frameworks\"
+        COMMAND if test x${_CEGUI_BUILD_CONFIG} == xDebug \; then ce_ext=\"${CEGUI_BUILD_SUFFIX}\"\; else ce_ext=\"\"\; fi\; mkdir -p \"${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${_TARGET_NAME}$$ce_ext.app/Contents/Frameworks\"
         COMMENT "Creating Frameworks directory ${_TARGET_NAME}.app")
     add_custom_command(TARGET ${_TARGET_NAME} POST_BUILD 
-        COMMAND if [ x${_CEGUI_BUILD_CONFIG} == xDebug ]\; then ce_ext=\"${CEGUI_BUILD_SUFFIX}\"\; else ce_ext=\"\"\; fi\; mkdir -p \"${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${_TARGET_NAME}$$ce_ext.app/Contents/Resources\"
+        COMMAND if test x${_CEGUI_BUILD_CONFIG} == xDebug \; then ce_ext=\"${CEGUI_BUILD_SUFFIX}\"\; else ce_ext=\"\"\; fi\; mkdir -p \"${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${_TARGET_NAME}$$ce_ext.app/Contents/Resources\"
         COMMENT "Creating Resources directory ${_TARGET_NAME}.app")
 
     if (NOT ${_STATIC})
         if (NOT CEGUI_BUILD_SHARED_LIBS_WITH_STATIC_DEPENDENCIES)
             add_custom_command(TARGET ${_TARGET_NAME} POST_BUILD 
-                COMMAND if [ x${_CEGUI_BUILD_CONFIG} == xDebug ]\; then ce_ext=\"${CEGUI_BUILD_SUFFIX}\"\; ce_libglob=\"*${CEGUI_BUILD_SUFFIX}.dylib\"\; else ce_ext=\"\"\; shopt -s extglob\; ce_libglob=\"!\(*${CEGUI_BUILD_SUFFIX}\).dylib\"\; fi\; ${_ACTIONCMD} ${CMAKE_PREFIX_PATH}/lib/dynamic/$$ce_libglob \"${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${_TARGET_NAME}$$ce_ext.app/Contents/Frameworks/\"
+                COMMAND if test x${_CEGUI_BUILD_CONFIG} == xDebug \; then ce_ext=\"${CEGUI_BUILD_SUFFIX}\"\; ce_libglob=\"*${CEGUI_BUILD_SUFFIX}.dylib\"\; else ce_ext=\"\"\; shopt -s extglob\; ce_libglob=\"!\(*${CEGUI_BUILD_SUFFIX}\).dylib\"\; fi\; ${_ACTIONCMD} ${CMAKE_PREFIX_PATH}/lib/dynamic/$$ce_libglob \"${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${_TARGET_NAME}$$ce_ext.app/Contents/Frameworks/\"
                 COMMENT "Creating ${_ACTIONMSG} dependency libraries in ${_TARGET_NAME}.app")
         endif()
 
         add_custom_command(TARGET ${_TARGET_NAME} POST_BUILD 
-            COMMAND if [ x${_CEGUI_BUILD_CONFIG} == xDebug ]\; then ce_ext=\"${CEGUI_BUILD_SUFFIX}\"\; ce_libglob=\"*${CEGUI_BUILD_SUFFIX}.dylib\"\; else ce_ext=\"\"\; shopt -s extglob\; ce_libglob=\"!\(*${CEGUI_BUILD_SUFFIX}\).dylib\"\; fi\; ${_ACTIONCMD} ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}/$$ce_libglob \"${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${_TARGET_NAME}$$ce_ext.app/Contents/Frameworks/\"
+            COMMAND if test x${_CEGUI_BUILD_CONFIG} == xDebug \; then ce_ext=\"${CEGUI_BUILD_SUFFIX}\"\; ce_libglob=\"*${CEGUI_BUILD_SUFFIX}.dylib\"\; else ce_ext=\"\"\; shopt -s extglob\; ce_libglob=\"!\(*${CEGUI_BUILD_SUFFIX}\).dylib\"\; fi\; ${_ACTIONCMD} ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}/$$ce_libglob \"${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${_TARGET_NAME}$$ce_ext.app/Contents/Frameworks/\"
             COMMENT "Creating ${_ACTIONMSG} built cegui libraries in ${_TARGET_NAME}.app")
     endif()
 
     add_custom_command(TARGET ${_TARGET_NAME} POST_BUILD 
-        COMMAND if [ x${_CEGUI_BUILD_CONFIG} == xDebug ]\; then ce_ext=\"${CEGUI_BUILD_SUFFIX}\"\; else ce_ext=\"\"\; fi\; ${_ACTIONCMD} ${CMAKE_SOURCE_DIR}/datafiles \"${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${_TARGET_NAME}$$ce_ext.app/Contents/Resources/\"
+        COMMAND if test x${_CEGUI_BUILD_CONFIG} == xDebug \; then ce_ext=\"${CEGUI_BUILD_SUFFIX}\"\; else ce_ext=\"\"\; fi\; ${_ACTIONCMD} ${CMAKE_SOURCE_DIR}/datafiles \"${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${_TARGET_NAME}$$ce_ext.app/Contents/Resources/\"
         COMMENT "Creating ${_ACTIONMSG} sample datafiles ${_TARGET_NAME}.app")
 
     # When CEGUI_APPLE_SYMLINK_DEPENDENCIES_TO_SAMPLE_APPS is TRUE, this
@@ -345,7 +345,7 @@
     # CEGUI_APPLE_SYMLINK_DEPENDENCIES_TO_SAMPLE_APPS to false and the thing
     # will be copied to the output app bundle instead.
     add_custom_command(TARGET ${_TARGET_NAME} POST_BUILD 
-        COMMAND if [ x${_CEGUI_BUILD_CONFIG} == xDebug ]\; then ce_ext=\"${CEGUI_BUILD_SUFFIX}\"\; else ce_ext=\"\"\; fi\; ${_ACTIONCMD} ${CMAKE_BINARY_DIR}/datafiles/samples \"${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${_TARGET_NAME}$$ce_ext.app/Contents/Resources/datafiles\"
+        COMMAND if test x${_CEGUI_BUILD_CONFIG} == xDebug \; then ce_ext=\"${CEGUI_BUILD_SUFFIX}\"\; else ce_ext=\"\"\; fi\; ${_ACTIONCMD} ${CMAKE_BINARY_DIR}/datafiles/samples \"${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${_TARGET_NAME}$$ce_ext.app/Contents/Resources/datafiles\"
         COMMENT "Creating ${_ACTIONMSG} samples.xml ${_TARGET_NAME}.app")
 endmacro()
 
