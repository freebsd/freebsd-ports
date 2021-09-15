--- cmake/modules/FindTBB.cmake.orig	2021-07-16 10:14:03 UTC
+++ cmake/modules/FindTBB.cmake
@@ -1,332 +1,456 @@
-# The MIT License (MIT)
+# - Find ThreadingBuildingBlocks include dirs and libraries
+# Use this module by invoking find_package with the form:
+#  find_package(TBB
+#    [REQUIRED]             # Fail with error if TBB is not found
+#    )                      #
+# Once done, this will define
 #
-# Copyright (c) 2015 Justus Calvin
-# 
-# Permission is hereby granted, free of charge, to any person obtaining a copy
-# of this software and associated documentation files (the "Software"), to deal
-# in the Software without restriction, including without limitation the rights
-# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
-# copies of the Software, and to permit persons to whom the Software is
-# furnished to do so, subject to the following conditions:
-# 
-# The above copyright notice and this permission notice shall be included in all
-# copies or substantial portions of the Software.
-# 
-# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
-# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
-# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
-# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
-# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
-# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
-# SOFTWARE.
-
+#  TBB_FOUND - system has TBB
+#  TBB_INCLUDE_DIRS - the TBB include directories
+#  TBB_LIBRARIES - TBB libraries to be lined, doesn't include malloc or
+#                  malloc proxy
+#  TBB::tbb - imported target for the TBB library
 #
-# FindTBB
-# -------
+#  TBB_VERSION_MAJOR - Major Product Version Number
+#  TBB_VERSION_MINOR - Minor Product Version Number
+#  TBB_INTERFACE_VERSION - Engineering Focused Version Number
+#  TBB_COMPATIBLE_INTERFACE_VERSION - The oldest major interface version
+#                                     still supported. This uses the engineering
+#                                     focused interface version numbers.
 #
-# Find TBB include directories and libraries.
+#  TBB_MALLOC_FOUND - system has TBB malloc library
+#  TBB_MALLOC_INCLUDE_DIRS - the TBB malloc include directories
+#  TBB_MALLOC_LIBRARIES - The TBB malloc libraries to be lined
+#  TBB::malloc - imported target for the TBB malloc library
 #
-# Usage:
+#  TBB_MALLOC_PROXY_FOUND - system has TBB malloc proxy library
+#  TBB_MALLOC_PROXY_INCLUDE_DIRS = the TBB malloc proxy include directories
+#  TBB_MALLOC_PROXY_LIBRARIES - The TBB malloc proxy libraries to be lined
+#  TBB::malloc_proxy - imported target for the TBB malloc proxy library
 #
-#  find_package(TBB [major[.minor]] [EXACT]
-#               [QUIET] [REQUIRED]
-#               [[COMPONENTS] [components...]]
-#               [OPTIONAL_COMPONENTS components...]) 
 #
-# where the allowed components are tbbmalloc and tbb_preview. Users may modify 
-# the behavior of this module with the following variables:
+# This module reads hints about search locations from variables:
+#  ENV TBB_ARCH_PLATFORM - for eg. set it to "mic" for Xeon Phi builds
+#  ENV TBB_ROOT or just TBB_ROOT - root directory of tbb installation
+#  ENV TBB_BUILD_PREFIX - specifies the build prefix for user built tbb
+#                         libraries. Should be specified with ENV TBB_ROOT
+#                         and optionally...
+#  ENV TBB_BUILD_DIR - if build directory is different than ${TBB_ROOT}/build
 #
-# * TBB_ROOT_DIR          - The base directory the of TBB installation.
-# * TBB_INCLUDE_DIR       - The directory that contains the TBB headers files.
-# * TBB_LIBRARY           - The directory that contains the TBB library files.
-# * TBB_<library>_LIBRARY - The path of the TBB the corresponding TBB library. 
-#                           These libraries, if specified, override the 
-#                           corresponding library search results, where <library>
-#                           may be tbb, tbb_debug, tbbmalloc, tbbmalloc_debug,
-#                           tbb_preview, or tbb_preview_debug.
-# * TBB_USE_DEBUG_BUILD   - The debug version of tbb libraries, if present, will
-#                           be used instead of the release version.
-# * TBB_STATIC            - Static linking of libraries with a _static suffix.
-#                           For example, on Windows a tbb_static.lib will be searched for
-#                           instead of tbb.lib.
 #
-# Users may modify the behavior of this module with the following environment
-# variables:
+# Modified by Robert Maynard from the original OGRE source
 #
-# * TBB_INSTALL_DIR 
-# * TBBROOT
-# * LIBRARY_PATH
+#-------------------------------------------------------------------
+# This file is part of the CMake build system for OGRE
+#     (Object-oriented Graphics Rendering Engine)
+# For the latest info, see http://www.ogre3d.org/
 #
-# This module will set the following variables:
+# The contents of this file are placed in the public domain. Feel
+# free to make use of it in any way you like.
+#-------------------------------------------------------------------
 #
-# * TBB_FOUND             - Set to false, or undefined, if we haven’t found, or
-#                           don’t want to use TBB.
-# * TBB_<component>_FOUND - If False, optional <component> part of TBB sytem is
-#                           not available.
-# * TBB_VERSION           - The full version string
-# * TBB_VERSION_MAJOR     - The major version
-# * TBB_VERSION_MINOR     - The minor version
-# * TBB_INTERFACE_VERSION - The interface version number defined in 
-#                           tbb/tbb_stddef.h.
-# * TBB_<library>_LIBRARY_RELEASE - The path of the TBB release version of 
-#                           <library>, where <library> may be tbb, tbb_debug,
-#                           tbbmalloc, tbbmalloc_debug, tbb_preview, or 
-#                           tbb_preview_debug.
-# * TBB_<library>_LIBRARY_DEGUG - The path of the TBB release version of 
-#                           <library>, where <library> may be tbb, tbb_debug,
-#                           tbbmalloc, tbbmalloc_debug, tbb_preview, or 
-#                           tbb_preview_debug.
+#=============================================================================
+# Copyright 2010-2012 Kitware, Inc.
+# Copyright 2012      Rolf Eike Beer <eike@sf-mail.de>
 #
-# The following varibles should be used to build and link with TBB:
+# Distributed under the OSI-approved BSD License (the "License");
+# see accompanying file Copyright.txt for details.
 #
-# * TBB_INCLUDE_DIRS        - The include directory for TBB.
-# * TBB_LIBRARIES           - The libraries to link against to use TBB.
-# * TBB_LIBRARIES_RELEASE   - The release libraries to link against to use TBB.
-# * TBB_LIBRARIES_DEBUG     - The debug libraries to link against to use TBB.
-# * TBB_DEFINITIONS         - Definitions to use when compiling code that uses
-#                             TBB.
-# * TBB_DEFINITIONS_RELEASE - Definitions to use when compiling release code that
-#                             uses TBB.
-# * TBB_DEFINITIONS_DEBUG   - Definitions to use when compiling debug code that
-#                             uses TBB.
+# This software is distributed WITHOUT ANY WARRANTY; without even the
+# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
+# See the License for more information.
+#=============================================================================
+# (To distribute this file outside of CMake, substitute the full
+#  License text for the above reference.)
+
+
+#=============================================================================
+#  FindTBB helper functions and macros
 #
-# This module will also create the "tbb" target that may be used when building
-# executables and libraries.
 
-unset(TBB_FOUND CACHE)
-unset(TBB_INCLUDE_DIRS CACHE)
-unset(TBB_LIBRARIES)
-unset(TBB_LIBRARIES_DEBUG)
-unset(TBB_LIBRARIES_RELEASE)
+# Use TBBConfig.cmake if possible.
 
-include(FindPackageHandleStandardArgs)
+set(_tbb_find_quiet)
+if (TBB_FIND_QUIETLY)
+  set(_tbb_find_quiet QUIET)
+endif ()
+set(_tbb_find_components)
+set(_tbb_find_optional_components)
+foreach (_tbb_find_component IN LISTS TBB_FIND_COMPONENTS)
+  if (TBB_FIND_REQUIRED_${_tbb_find_component})
+    list(APPEND _tbb_find_components "${_tbb_find_component}")
+  else ()
+    list(APPEND _tbb_find_optional_components "${_tbb_find_component}")
+  endif ()
+endforeach ()
+unset(_tbb_find_component)
+find_package(TBB CONFIG ${_tbb_find_quiet}
+  COMPONENTS ${_tbb_find_components}
+  OPTIONAL_COMPONENTS ${_tbb_find_optional_components})
+unset(_tbb_find_quiet)
+unset(_tbb_find_components)
+unset(_tbb_find_optional_components)
+if (TBB_FOUND)
+  return ()
+endif ()
 
-find_package(Threads QUIET REQUIRED)
+#====================================================
+# Fix the library path in case it is a linker script
+#====================================================
+function(tbb_extract_real_library library real_library)
+  if(NOT UNIX OR NOT EXISTS ${library})
+    set(${real_library} "${library}" PARENT_SCOPE)
+    return()
+  endif()
 
-if(NOT TBB_FOUND)
+  #Read in the first 4 bytes and see if they are the ELF magic number
+  set(_elf_magic "7f454c46")
+  file(READ ${library} _hex_data OFFSET 0 LIMIT 4 HEX)
+  if(_hex_data STREQUAL _elf_magic)
+    #we have opened a elf binary so this is what
+    #we should link to
+    set(${real_library} "${library}" PARENT_SCOPE)
+    return()
+  endif()
 
-  ##################################
-  # Check the build type
-  ##################################
-  
-  if(NOT DEFINED TBB_USE_DEBUG_BUILD)
-    if(CMAKE_BUILD_TYPE MATCHES "(Debug|DEBUG|debug)")
-      set(TBB_BUILD_TYPE DEBUG)
-    else()
-      set(TBB_BUILD_TYPE RELEASE)
-    endif()
-  elseif(TBB_USE_DEBUG_BUILD)
-    set(TBB_BUILD_TYPE DEBUG)
+  file(READ ${library} _data OFFSET 0 LIMIT 1024)
+  if("${_data}" MATCHES "INPUT \\(([^(]+)\\)")
+    #extract out the .so name from REGEX MATCH command
+    set(_proper_so_name "${CMAKE_MATCH_1}")
+
+    #construct path to the real .so which is presumed to be in the same directory
+    #as the input file
+    get_filename_component(_so_dir "${library}" DIRECTORY)
+    set(${real_library} "${_so_dir}/${_proper_so_name}" PARENT_SCOPE)
   else()
-    set(TBB_BUILD_TYPE RELEASE)
+    #unable to determine what this library is so just hope everything works
+    #and pass it unmodified.
+    set(${real_library} "${library}" PARENT_SCOPE)
   endif()
-  
-  ##################################
-  # Set the TBB search directories
-  ##################################
-  
-  # Define search paths based on user input and environment variables
-  set(TBB_SEARCH_DIR ${TBB_ROOT_DIR} $ENV{TBB_INSTALL_DIR} $ENV{TBBROOT})
-  
-  # Define the search directories based on the current platform
-  if(CMAKE_SYSTEM_NAME STREQUAL "Windows")
-    set(TBB_DEFAULT_SEARCH_DIR "C:/Program Files/Intel/TBB"
-                               "C:/Program Files (x86)/Intel/TBB")
+endfunction()
 
-    # Set the target architecture
-    if(CMAKE_SIZEOF_VOID_P EQUAL 8)
-      set(TBB_ARCHITECTURE "intel64")
-    else()
-      set(TBB_ARCHITECTURE "ia32")
-    endif()
+#===============================================
+# Do the final processing for the package find.
+#===============================================
+macro(findpkg_finish PREFIX TARGET_NAME)
+  if (${PREFIX}_INCLUDE_DIR AND ${PREFIX}_LIBRARY)
+    set(${PREFIX}_FOUND TRUE)
+    set (${PREFIX}_INCLUDE_DIRS ${${PREFIX}_INCLUDE_DIR})
+    set (${PREFIX}_LIBRARIES ${${PREFIX}_LIBRARY})
+  else ()
+    if (${PREFIX}_FIND_REQUIRED AND NOT ${PREFIX}_FIND_QUIETLY)
+      message(FATAL_ERROR "Required library ${PREFIX} not found.")
+    endif ()
+  endif ()
 
-    # Set the TBB search library path search suffix based on the version of VC
-    if(WINDOWS_STORE)
-      set(TBB_LIB_PATH_SUFFIX "lib/${TBB_ARCHITECTURE}/vc11_ui")
-    elseif(MSVC14)
-      set(TBB_LIB_PATH_SUFFIX "lib/${TBB_ARCHITECTURE}/vc14")
-    elseif(MSVC12)
-      set(TBB_LIB_PATH_SUFFIX "lib/${TBB_ARCHITECTURE}/vc12")
-    elseif(MSVC11)
-      set(TBB_LIB_PATH_SUFFIX "lib/${TBB_ARCHITECTURE}/vc11")
-    elseif(MSVC10)
-      set(TBB_LIB_PATH_SUFFIX "lib/${TBB_ARCHITECTURE}/vc10")
-    endif()
+  if (NOT TARGET "TBB::${TARGET_NAME}")
+    if (${PREFIX}_LIBRARY_RELEASE)
+      tbb_extract_real_library(${${PREFIX}_LIBRARY_RELEASE} real_release)
+    endif ()
+    if (${PREFIX}_LIBRARY_DEBUG)
+      tbb_extract_real_library(${${PREFIX}_LIBRARY_DEBUG} real_debug)
+    endif ()
+    add_library(TBB::${TARGET_NAME} UNKNOWN IMPORTED)
+    set_target_properties(TBB::${TARGET_NAME} PROPERTIES
+      INTERFACE_INCLUDE_DIRECTORIES "${${PREFIX}_INCLUDE_DIR}")
+    if (${PREFIX}_LIBRARY_DEBUG AND ${PREFIX}_LIBRARY_RELEASE)
+      set_target_properties(TBB::${TARGET_NAME} PROPERTIES
+        IMPORTED_LOCATION "${real_release}"
+        IMPORTED_LOCATION_DEBUG "${real_debug}"
+        IMPORTED_LOCATION_RELEASE "${real_release}")
+    elseif (${PREFIX}_LIBRARY_RELEASE)
+      set_target_properties(TBB::${TARGET_NAME} PROPERTIES
+        IMPORTED_LOCATION "${real_release}")
+    elseif (${PREFIX}_LIBRARY_DEBUG)
+      set_target_properties(TBB::${TARGET_NAME} PROPERTIES
+        IMPORTED_LOCATION "${real_debug}")
+    endif ()
+  endif ()
 
-    # Add the library path search suffix for the VC independent version of TBB
-    list(APPEND TBB_LIB_PATH_SUFFIX "lib/${TBB_ARCHITECTURE}/vc_mt")
+  #mark the following variables as internal variables
+  mark_as_advanced(${PREFIX}_INCLUDE_DIR
+                   ${PREFIX}_LIBRARY
+                   ${PREFIX}_LIBRARY_DEBUG
+                   ${PREFIX}_LIBRARY_RELEASE)
+endmacro()
 
-  elseif(CMAKE_SYSTEM_NAME STREQUAL "Darwin")
-    # OS X
-    set(TBB_DEFAULT_SEARCH_DIR "/opt/intel/tbb")
-    
-    # TODO: Check to see which C++ library is being used by the compiler.
-    if(NOT ${CMAKE_SYSTEM_VERSION} VERSION_LESS 13.0)
-      # The default C++ library on OS X 10.9 and later is libc++
-      set(TBB_LIB_PATH_SUFFIX "lib/libc++" "lib")
-    else()
-      set(TBB_LIB_PATH_SUFFIX "lib")
-    endif()
-  elseif(CMAKE_SYSTEM_NAME STREQUAL "Linux")
-    # Linux
-    set(TBB_DEFAULT_SEARCH_DIR "/opt/intel/tbb")
-    
-    # TODO: Check compiler version to see the suffix should be <arch>/gcc4.1 or
-    #       <arch>/gcc4.1. For now, assume that the compiler is more recent than
-    #       gcc 4.4.x or later.
-    if(CMAKE_SYSTEM_PROCESSOR STREQUAL "x86_64")
-      set(TBB_LIB_PATH_SUFFIX "lib/intel64/gcc4.4")
-    elseif(CMAKE_SYSTEM_PROCESSOR MATCHES "^i.86$")
-      set(TBB_LIB_PATH_SUFFIX "lib/ia32/gcc4.4")
-    endif()
-  endif()
-  
-  ##################################
-  # Find the TBB include dir
-  ##################################
-  
-  find_path(TBB_INCLUDE_DIRS tbb/tbb.h
-      HINTS ${TBB_INCLUDE_DIR} ${TBB_SEARCH_DIR}
-      PATHS ${TBB_DEFAULT_SEARCH_DIR}
-      PATH_SUFFIXES include)
+#===============================================
+# Generate debug names from given release names
+#===============================================
+macro(get_debug_names PREFIX)
+  foreach(i ${${PREFIX}})
+    set(${PREFIX}_DEBUG ${${PREFIX}_DEBUG} ${i}d ${i}D ${i}_d ${i}_D ${i}_debug ${i})
+  endforeach()
+endmacro()
 
-  ##################################
-  # Set version strings
-  ##################################
+#===============================================
+# See if we have env vars to help us find tbb
+#===============================================
+macro(getenv_path VAR)
+   set(ENV_${VAR} $ENV{${VAR}})
+   # replace won't work if var is blank
+   if (ENV_${VAR})
+     string( REGEX REPLACE "\\\\" "/" ENV_${VAR} ${ENV_${VAR}} )
+   endif ()
+endmacro()
 
-  if(TBB_INCLUDE_DIRS)
-    file(READ "${TBB_INCLUDE_DIRS}/tbb/tbb_stddef.h" _tbb_version_file)
-    string(REGEX REPLACE ".*#define TBB_VERSION_MAJOR ([0-9]+).*" "\\1"
-        TBB_VERSION_MAJOR "${_tbb_version_file}")
-    string(REGEX REPLACE ".*#define TBB_VERSION_MINOR ([0-9]+).*" "\\1"
-        TBB_VERSION_MINOR "${_tbb_version_file}")
-    string(REGEX REPLACE ".*#define TBB_INTERFACE_VERSION ([0-9]+).*" "\\1"
-        TBB_INTERFACE_VERSION "${_tbb_version_file}")
-    set(TBB_VERSION "${TBB_VERSION_MAJOR}.${TBB_VERSION_MINOR}")
-  endif()
+#===============================================
+# Couple a set of release AND debug libraries
+#===============================================
+macro(make_library_set PREFIX)
+  if (${PREFIX}_RELEASE AND ${PREFIX}_DEBUG)
+    set(${PREFIX} optimized ${${PREFIX}_RELEASE} debug ${${PREFIX}_DEBUG})
+  elseif (${PREFIX}_RELEASE)
+    set(${PREFIX} ${${PREFIX}_RELEASE})
+  elseif (${PREFIX}_DEBUG)
+    set(${PREFIX} ${${PREFIX}_DEBUG})
+  endif ()
+endmacro()
 
-  ##################################
-  # Find TBB components
-  ##################################
 
-  if(TBB_VERSION VERSION_LESS 4.3)
-    set(TBB_SEARCH_COMPOMPONENTS tbb_preview tbbmalloc tbb)
-  else()
-    set(TBB_SEARCH_COMPOMPONENTS tbb_preview tbbmalloc_proxy tbbmalloc tbb)
-  endif()
+#=============================================================================
+#  Now to actually find TBB
+#
 
-  if(TBB_STATIC)
-    set(TBB_STATIC_SUFFIX "_static")
-  endif()
+# Get path, convert backslashes as ${ENV_${var}}
+getenv_path(TBB_ROOT)
 
-  # Find each component
-  foreach(_comp ${TBB_SEARCH_COMPOMPONENTS})
-    if(";${TBB_FIND_COMPONENTS};tbb;" MATCHES ";${_comp};")
+# initialize search paths
+set(TBB_PREFIX_PATH ${TBB_ROOT} ${ENV_TBB_ROOT})
+set(TBB_INC_SEARCH_PATH "")
+set(TBB_LIB_SEARCH_PATH "")
 
-      unset(TBB_${_comp}_LIBRARY_DEBUG CACHE)
-      unset(TBB_${_comp}_LIBRARY_RELEASE CACHE)
 
-      # Search for the libraries
-      find_library(TBB_${_comp}_LIBRARY_RELEASE ${_comp}${TBB_STATIC_SUFFIX}
-          HINTS ${TBB_LIBRARY} ${TBB_SEARCH_DIR}
-          PATHS ${TBB_DEFAULT_SEARCH_DIR} ENV LIBRARY_PATH
-          PATH_SUFFIXES ${TBB_LIB_PATH_SUFFIX})
+# If user built from sources
+set(TBB_BUILD_PREFIX $ENV{TBB_BUILD_PREFIX})
+if (TBB_BUILD_PREFIX AND ENV_TBB_ROOT)
+  getenv_path(TBB_BUILD_DIR)
+  if (NOT ENV_TBB_BUILD_DIR)
+    set(ENV_TBB_BUILD_DIR ${ENV_TBB_ROOT}/build)
+  endif ()
 
-      find_library(TBB_${_comp}_LIBRARY_DEBUG ${_comp}${TBB_STATIC_SUFFIX}_debug
-          HINTS ${TBB_LIBRARY} ${TBB_SEARCH_DIR}
-          PATHS ${TBB_DEFAULT_SEARCH_DIR} ENV LIBRARY_PATH
-          PATH_SUFFIXES ${TBB_LIB_PATH_SUFFIX})
+  # include directory under ${ENV_TBB_ROOT}/include
+  list(APPEND TBB_LIB_SEARCH_PATH
+    ${ENV_TBB_BUILD_DIR}/${TBB_BUILD_PREFIX}_release
+    ${ENV_TBB_BUILD_DIR}/${TBB_BUILD_PREFIX}_debug)
+endif ()
 
-      if(TBB_${_comp}_LIBRARY_DEBUG)
-        list(APPEND TBB_LIBRARIES_DEBUG "${TBB_${_comp}_LIBRARY_DEBUG}")
-      endif()
-      if(TBB_${_comp}_LIBRARY_RELEASE)
-        list(APPEND TBB_LIBRARIES_RELEASE "${TBB_${_comp}_LIBRARY_RELEASE}")
-      endif()
-      if(TBB_${_comp}_LIBRARY_${TBB_BUILD_TYPE} AND NOT TBB_${_comp}_LIBRARY)
-        set(TBB_${_comp}_LIBRARY "${TBB_${_comp}_LIBRARY_${TBB_BUILD_TYPE}}")
-      endif()
 
-      if(TBB_${_comp}_LIBRARY AND EXISTS "${TBB_${_comp}_LIBRARY}")
-        set(TBB_${_comp}_FOUND TRUE)
-      else()
-        set(TBB_${_comp}_FOUND FALSE)
-      endif()
+# For Windows, let's assume that the user might be using the precompiled
+# TBB packages from the main website. These use a rather awkward directory
+# structure (at least for automatically finding the right files) depending
+# on platform and compiler, but we'll do our best to accommodate it.
+# Not adding the same effort for the precompiled linux builds, though. Those
+# have different versions for CC compiler versions and linux kernels which
+# will never adequately match the user's setup, so there is no feasible way
+# to detect the "best" version to use. The user will have to manually
+# select the right files. (Chances are the distributions are shipping their
+# custom version of tbb, anyway, so the problem is probably nonexistent.)
+if (WIN32 AND MSVC)
+  set(COMPILER_PREFIX "vc7.1")
+  if (MSVC_VERSION EQUAL 1400)
+    set(COMPILER_PREFIX "vc8")
+  elseif(MSVC_VERSION EQUAL 1500)
+    set(COMPILER_PREFIX "vc9")
+  elseif(MSVC_VERSION EQUAL 1600)
+    set(COMPILER_PREFIX "vc10")
+  elseif(MSVC_VERSION EQUAL 1700)
+    set(COMPILER_PREFIX "vc11")
+  elseif(MSVC_VERSION EQUAL 1800)
+    set(COMPILER_PREFIX "vc12")
+  elseif(MSVC_VERSION GREATER_EQUAL 1900)
+    set(COMPILER_PREFIX "vc14")
+  endif ()
 
-      # Mark internal variables as advanced
-      mark_as_advanced(TBB_${_comp}_LIBRARY_RELEASE)
-      mark_as_advanced(TBB_${_comp}_LIBRARY_DEBUG)
-      mark_as_advanced(TBB_${_comp}_LIBRARY)
+  # for each prefix path, add ia32/64\${COMPILER_PREFIX}\lib to the lib search path
+  foreach (dir IN LISTS TBB_PREFIX_PATH)
+    if (CMAKE_CL_64)
+      list(APPEND TBB_LIB_SEARCH_PATH ${dir}/ia64/${COMPILER_PREFIX}/lib)
+      list(APPEND TBB_LIB_SEARCH_PATH ${dir}/lib/ia64/${COMPILER_PREFIX})
+      list(APPEND TBB_LIB_SEARCH_PATH ${dir}/intel64/${COMPILER_PREFIX}/lib)
+      list(APPEND TBB_LIB_SEARCH_PATH ${dir}/lib/intel64/${COMPILER_PREFIX})
+    else ()
+      list(APPEND TBB_LIB_SEARCH_PATH ${dir}/ia32/${COMPILER_PREFIX}/lib)
+      list(APPEND TBB_LIB_SEARCH_PATH ${dir}/lib/ia32/${COMPILER_PREFIX})
+    endif ()
+  endforeach ()
+endif ()
 
-    endif()
-  endforeach()
+# For OS X binary distribution, choose libc++ based libraries for Mavericks (10.9)
+# and above and AppleClang
+if (CMAKE_SYSTEM_NAME STREQUAL "Darwin" AND
+    NOT CMAKE_SYSTEM_VERSION VERSION_LESS 13.0)
+  set (USE_LIBCXX OFF)
+  cmake_policy(GET CMP0025 POLICY_VAR)
 
-  ##################################
-  # Set compile flags and libraries
-  ##################################
+  if (POLICY_VAR STREQUAL "NEW")
+    if (CMAKE_CXX_COMPILER_ID STREQUAL "AppleClang")
+      set (USE_LIBCXX ON)
+    endif ()
+  else ()
+    if (CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
+      set (USE_LIBCXX ON)
+    endif ()
+  endif ()
 
-  set(TBB_DEFINITIONS_RELEASE "")
-  set(TBB_DEFINITIONS_DEBUG "TBB_USE_DEBUG=1")
-    
-  if(TBB_LIBRARIES_${TBB_BUILD_TYPE})
-    set(TBB_LIBRARIES "${TBB_LIBRARIES_${TBB_BUILD_TYPE}}")
+  if (USE_LIBCXX)
+    foreach (dir IN LISTS TBB_PREFIX_PATH)
+      list (APPEND TBB_LIB_SEARCH_PATH ${dir}/lib/libc++ ${dir}/libc++/lib)
+    endforeach ()
+  endif ()
+endif ()
+
+# check compiler ABI
+if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
+  set(COMPILER_PREFIX)
+  if (NOT CMAKE_CXX_COMPILER_VERSION VERSION_LESS 4.8)
+    list(APPEND COMPILER_PREFIX "gcc4.8")
   endif()
-  
-  if(NOT MSVC AND NOT TBB_LIBRARIES)
-    set(TBB_LIBRARIES ${TBB_LIBRARIES_RELEASE})
+  if (NOT CMAKE_CXX_COMPILER_VERSION VERSION_LESS 4.7)
+    list(APPEND COMPILER_PREFIX "gcc4.7")
   endif()
+  if (NOT CMAKE_CXX_COMPILER_VERSION VERSION_LESS 4.4)
+    list(APPEND COMPILER_PREFIX "gcc4.4")
+  endif()
+  list(APPEND COMPILER_PREFIX "gcc4.1")
+elseif(CMAKE_CXX_COMPILER_ID MATCHES "Clang")
+  set(COMPILER_PREFIX)
+  if (NOT CMAKE_CXX_COMPILER_VERSION VERSION_LESS 4.0) # Complete guess
+    list(APPEND COMPILER_PREFIX "gcc4.8")
+  endif()
+  if (NOT CMAKE_CXX_COMPILER_VERSION VERSION_LESS 3.6)
+    list(APPEND COMPILER_PREFIX "gcc4.7")
+  endif()
+  list(APPEND COMPILER_PREFIX "gcc4.4")
+else() # Assume compatibility with 4.4 for other compilers
+  list(APPEND COMPILER_PREFIX "gcc4.4")
+endif ()
 
-  set(TBB_DEFINITIONS "")
-  if (MSVC AND TBB_STATIC)
-    set(TBB_DEFINITIONS __TBB_NO_IMPLICIT_LINKAGE)
-  endif ()
+# if platform architecture is explicitly specified
+set(TBB_ARCH_PLATFORM $ENV{TBB_ARCH_PLATFORM})
+if (TBB_ARCH_PLATFORM)
+  foreach (dir IN LISTS TBB_PREFIX_PATH)
+    list(APPEND TBB_LIB_SEARCH_PATH ${dir}/${TBB_ARCH_PLATFORM}/lib)
+    list(APPEND TBB_LIB_SEARCH_PATH ${dir}/lib/${TBB_ARCH_PLATFORM})
+  endforeach ()
+endif ()
 
-  unset (TBB_STATIC_SUFFIX)
+foreach (dir IN LISTS TBB_PREFIX_PATH)
+  foreach (prefix IN LISTS COMPILER_PREFIX)
+    if (CMAKE_SIZEOF_VOID_P EQUAL 8)
+      list(APPEND TBB_LIB_SEARCH_PATH ${dir}/lib/intel64)
+      list(APPEND TBB_LIB_SEARCH_PATH ${dir}/lib/intel64/${prefix})
+      list(APPEND TBB_LIB_SEARCH_PATH ${dir}/intel64/lib)
+      list(APPEND TBB_LIB_SEARCH_PATH ${dir}/intel64/${prefix}/lib)
+    else ()
+      list(APPEND TBB_LIB_SEARCH_PATH ${dir}/lib/ia32)
+      list(APPEND TBB_LIB_SEARCH_PATH ${dir}/lib/ia32/${prefix})
+      list(APPEND TBB_LIB_SEARCH_PATH ${dir}/ia32/lib)
+      list(APPEND TBB_LIB_SEARCH_PATH ${dir}/ia32/${prefix}/lib)
+    endif ()
+  endforeach()
+endforeach ()
 
-  find_package_handle_standard_args(TBB 
-      REQUIRED_VARS TBB_INCLUDE_DIRS TBB_LIBRARIES
-      FAIL_MESSAGE "TBB library cannot be found. Consider set TBBROOT environment variable."
-      HANDLE_COMPONENTS
-      VERSION_VAR TBB_VERSION)
+# add general search paths
+foreach (dir IN LISTS TBB_PREFIX_PATH)
+  list(APPEND TBB_LIB_SEARCH_PATH ${dir}/lib ${dir}/Lib ${dir}/lib/tbb
+    ${dir}/Libs)
+  list(APPEND TBB_INC_SEARCH_PATH ${dir}/include ${dir}/Include
+    ${dir}/include/tbb)
+endforeach ()
 
-  ##################################
-  # Create targets
-  ##################################
+set(TBB_LIBRARY_NAMES tbb)
+get_debug_names(TBB_LIBRARY_NAMES)
 
-  if(NOT CMAKE_VERSION VERSION_LESS 3.0 AND TBB_FOUND)
-    add_library(TBB::tbb UNKNOWN IMPORTED)
-    set_target_properties(TBB::tbb PROPERTIES
-          INTERFACE_COMPILE_DEFINITIONS "${TBB_DEFINITIONS}"
-          INTERFACE_LINK_LIBRARIES  "Threads::Threads;${CMAKE_DL_LIBS}"
-          INTERFACE_INCLUDE_DIRECTORIES  ${TBB_INCLUDE_DIRS}
-          IMPORTED_LOCATION              ${TBB_LIBRARIES})
-    if(TBB_LIBRARIES_RELEASE AND TBB_LIBRARIES_DEBUG)
-      set_target_properties(TBB::tbb PROPERTIES
-          INTERFACE_COMPILE_DEFINITIONS "${TBB_DEFINITIONS};$<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:${TBB_DEFINITIONS_DEBUG}>;$<$<CONFIG:Release>:${TBB_DEFINITIONS_RELEASE}>"
-          IMPORTED_LOCATION_DEBUG          ${TBB_LIBRARIES_DEBUG}
-          IMPORTED_LOCATION_RELWITHDEBINFO ${TBB_LIBRARIES_RELEASE}
-          IMPORTED_LOCATION_RELEASE        ${TBB_LIBRARIES_RELEASE}
-          IMPORTED_LOCATION_MINSIZEREL     ${TBB_LIBRARIES_RELEASE}
-          )
-    endif()
-  endif()
 
-  mark_as_advanced(TBB_INCLUDE_DIRS TBB_LIBRARIES)
+find_path(TBB_INCLUDE_DIR
+          NAMES tbb/tbb.h
+          PATHS ${TBB_INC_SEARCH_PATH})
 
-  unset(TBB_ARCHITECTURE)
-  unset(TBB_BUILD_TYPE)
-  unset(TBB_LIB_PATH_SUFFIX)
-  unset(TBB_DEFAULT_SEARCH_DIR)
+find_library(TBB_LIBRARY_RELEASE
+             NAMES ${TBB_LIBRARY_NAMES}
+             PATHS ${TBB_LIB_SEARCH_PATH})
+find_library(TBB_LIBRARY_DEBUG
+             NAMES ${TBB_LIBRARY_NAMES_DEBUG}
+             PATHS ${TBB_LIB_SEARCH_PATH})
+make_library_set(TBB_LIBRARY)
 
-  if(TBB_DEBUG)
-    message(STATUS "  TBB_FOUND               = ${TBB_FOUND}")
-    message(STATUS "  TBB_INCLUDE_DIRS        = ${TBB_INCLUDE_DIRS}")
-    message(STATUS "  TBB_DEFINITIONS         = ${TBB_DEFINITIONS}")
-    message(STATUS "  TBB_LIBRARIES           = ${TBB_LIBRARIES}")
-    message(STATUS "  TBB_DEFINITIONS_DEBUG   = ${TBB_DEFINITIONS_DEBUG}")
-    message(STATUS "  TBB_LIBRARIES_DEBUG     = ${TBB_LIBRARIES_DEBUG}")
-    message(STATUS "  TBB_DEFINITIONS_RELEASE = ${TBB_DEFINITIONS_RELEASE}")
-    message(STATUS "  TBB_LIBRARIES_RELEASE   = ${TBB_LIBRARIES_RELEASE}")
+findpkg_finish(TBB tbb)
+
+#if we haven't found TBB no point on going any further
+if (NOT TBB_FOUND)
+  return()
+endif ()
+
+#=============================================================================
+# Look for TBB's malloc package
+set(TBB_MALLOC_LIBRARY_NAMES tbbmalloc)
+get_debug_names(TBB_MALLOC_LIBRARY_NAMES)
+
+find_path(TBB_MALLOC_INCLUDE_DIR
+          NAMES tbb/tbb.h
+          PATHS ${TBB_INC_SEARCH_PATH})
+
+find_library(TBB_MALLOC_LIBRARY_RELEASE
+             NAMES ${TBB_MALLOC_LIBRARY_NAMES}
+             PATHS ${TBB_LIB_SEARCH_PATH})
+find_library(TBB_MALLOC_LIBRARY_DEBUG
+             NAMES ${TBB_MALLOC_LIBRARY_NAMES_DEBUG}
+             PATHS ${TBB_LIB_SEARCH_PATH})
+make_library_set(TBB_MALLOC_LIBRARY)
+
+findpkg_finish(TBB_MALLOC tbbmalloc)
+
+#=============================================================================
+# Look for TBB's malloc proxy package
+set(TBB_MALLOC_PROXY_LIBRARY_NAMES tbbmalloc_proxy)
+get_debug_names(TBB_MALLOC_PROXY_LIBRARY_NAMES)
+
+find_path(TBB_MALLOC_PROXY_INCLUDE_DIR
+          NAMES tbb/tbbmalloc_proxy.h
+          PATHS ${TBB_INC_SEARCH_PATH})
+
+find_library(TBB_MALLOC_PROXY_LIBRARY_RELEASE
+             NAMES ${TBB_MALLOC_PROXY_LIBRARY_NAMES}
+             PATHS ${TBB_LIB_SEARCH_PATH})
+find_library(TBB_MALLOC_PROXY_LIBRARY_DEBUG
+             NAMES ${TBB_MALLOC_PROXY_LIBRARY_NAMES_DEBUG}
+             PATHS ${TBB_LIB_SEARCH_PATH})
+make_library_set(TBB_MALLOC_PROXY_LIBRARY)
+
+findpkg_finish(TBB_MALLOC_PROXY tbbmalloc_proxy)
+
+
+#=============================================================================
+#parse all the version numbers from tbb
+if(NOT TBB_VERSION)
+  if (EXISTS "${TBB_INCLUDE_DIR}/oneapi/tbb/version.h")
+    file(STRINGS
+      "${TBB_INCLUDE_DIR}/oneapi/tbb/version.h"
+      TBB_VERSION_CONTENTS
+      REGEX "VERSION")
+  else()
+    #only read the start of the file
+    file(STRINGS
+      "${TBB_INCLUDE_DIR}/tbb/tbb_stddef.h"
+      TBB_VERSION_CONTENTS
+      REGEX "VERSION")
   endif()
+
+  string(REGEX REPLACE
+    ".*#define TBB_VERSION_MAJOR ([0-9]+).*" "\\1"
+    TBB_VERSION_MAJOR "${TBB_VERSION_CONTENTS}")
+
+  string(REGEX REPLACE
+    ".*#define TBB_VERSION_MINOR ([0-9]+).*" "\\1"
+    TBB_VERSION_MINOR "${TBB_VERSION_CONTENTS}")
+
+  string(REGEX REPLACE
+        ".*#define TBB_INTERFACE_VERSION ([0-9]+).*" "\\1"
+        TBB_INTERFACE_VERSION "${TBB_VERSION_CONTENTS}")
+
+  string(REGEX REPLACE
+        ".*#define TBB_COMPATIBLE_INTERFACE_VERSION ([0-9]+).*" "\\1"
+        TBB_COMPATIBLE_INTERFACE_VERSION "${TBB_VERSION_CONTENTS}")
 
 endif()
