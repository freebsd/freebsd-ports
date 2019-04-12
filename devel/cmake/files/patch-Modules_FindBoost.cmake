--- Modules/FindBoost.cmake.orig	2019-02-07 20:55:01 UTC
+++ Modules/FindBoost.cmake
@@ -56,6 +56,8 @@ This module reads hints about search locations from va
    (or BOOSTROOT)
   BOOST_INCLUDEDIR       - Preferred include directory e.g. <prefix>/include
   BOOST_LIBRARYDIR       - Preferred library directory e.g. <prefix>/lib
+  BOOST_PYTHON_SUFFIX    - Preferred Python version
+
   Boost_NO_SYSTEM_PATHS  - Set to ON to disable searching in locations not
                            specified by these hint variables. Default is OFF.
   Boost_ADDITIONAL_VERSIONS
@@ -242,6 +244,9 @@ Set Boost_NO_BOOST_CMAKE to ON to disable the search f
 cmake_policy(PUSH)
 cmake_policy(SET CMP0057 NEW) # if IN_LIST
 
+# https://gitlab.kitware.com/cmake/cmake/issues/18865
+set(Boost_NO_BOOST_CMAKE ON CACHE BOOL "Disable the search for boost-cmake")
+
 #-------------------------------------------------------------------------------
 # Before we go searching, check whether boost-cmake is available, unless the
 # user specifically asked NOT to search for boost-cmake.
@@ -1739,10 +1744,10 @@ foreach(COMPONENT ${Boost_FIND_COMPONENTS})
   # Handle Python version suffixes
   unset(COMPONENT_PYTHON_VERSION_MAJOR)
   unset(COMPONENT_PYTHON_VERSION_MINOR)
-  if(${COMPONENT} MATCHES "^(python|mpi_python|numpy)([0-9])\$")
+  if(${COMPONENT}${BOOST_PYTHON_SUFFIX} MATCHES "^(python|mpi_python|numpy)([0-9])\$")
     set(COMPONENT_UNVERSIONED "${CMAKE_MATCH_1}")
     set(COMPONENT_PYTHON_VERSION_MAJOR "${CMAKE_MATCH_2}")
-  elseif(${COMPONENT} MATCHES "^(python|mpi_python|numpy)([0-9])\\.?([0-9])\$")
+  elseif(${COMPONENT}${BOOST_PYTHON_SUFFIX} MATCHES "^(python|mpi_python|numpy)([0-9])\\.?([0-9])\$")
     set(COMPONENT_UNVERSIONED "${CMAKE_MATCH_1}")
     set(COMPONENT_PYTHON_VERSION_MAJOR "${CMAKE_MATCH_2}")
     set(COMPONENT_PYTHON_VERSION_MINOR "${CMAKE_MATCH_3}")
